#pragma once

namespace opaline::ui {

	struct color
	{
		float r{};
		float g{};
		float b{};
		float a{ 1.0f };

		[[nodiscard]] ImVec4 vec4( float alpha ) const noexcept { return { this->r, this->g, this->b, alpha }; }
	};

	inline void to_json( nlohmann::json& out, const color& value )
	{
		out = nlohmann::json::array( { value.r, value.g, value.b, value.a } );
	}

	inline void from_json( const nlohmann::json& in, color& value )
	{
		value = { in.at( 0 ).get<float>( ), in.at( 1 ).get<float>( ), in.at( 2 ).get<float>( ), in.at( 3 ).get<float>( ) };
	}

	class setting_base
	{
	public:
		setting_base( std::string_view group, std::string_view name );
		virtual ~setting_base( ) = default;

		[[nodiscard]] const std::string& group( ) const noexcept { return this->m_group; }
		[[nodiscard]] const std::string& name( ) const noexcept { return this->m_name; }

		[[nodiscard]] virtual nlohmann::json save( ) const = 0;
		virtual void load( const nlohmann::json& value ) = 0;
		virtual void reset( ) = 0;

	private:
		std::string m_group{};
		std::string m_name{};
	};

	template <typename type>
	class setting final : public setting_base
	{
	public:
		setting( std::string_view group, std::string_view name, type value ) : setting_base( group, name ), m_value( value ), m_default( value ) {}

		[[nodiscard]] type& get( ) noexcept { return this->m_value; }
		[[nodiscard]] const type& get( ) const noexcept { return this->m_value; }

		[[nodiscard]] nlohmann::json save( ) const override { return this->m_value; }
		void load( const nlohmann::json& value ) override { this->m_value = value.get<type>( ); }
		void reset( ) override { this->m_value = this->m_default; }

	private:
		type m_value{};
		type m_default{};
	};

	class config
	{
	public:
		void initialize( );
		void add( setting_base* setting );

		[[nodiscard]] std::vector<std::string> list( ) const;
		[[nodiscard]] bool save( std::string_view name ) const;
		[[nodiscard]] bool load( std::string_view name );
		[[nodiscard]] bool remove( std::string_view name ) const;

	private:
		[[nodiscard]] std::optional<std::filesystem::path> path( std::string_view name ) const;

		std::filesystem::path m_directory{};
		std::vector<setting_base*> m_settings{};
	};

	inline config g_config{};

} // namespace opaline::ui
