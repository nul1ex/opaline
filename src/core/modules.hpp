#pragma once

namespace opaline::core {

	class address
	{
	public:
		address( ) = default;
		explicit address( std::uintptr_t value ) noexcept : m_value( value ) { }

		[[nodiscard]] std::uintptr_t value( ) const noexcept { return this->m_value; }

		[[nodiscard]] address add( std::ptrdiff_t offset ) const noexcept
		{
			return address{ this->m_value ? this->m_value + static_cast< std::uintptr_t >( offset ) : 0 };
		}

		[[nodiscard]] address deref( ) const noexcept
		{
			return address{ this->m_value ? *reinterpret_cast< const std::uintptr_t* >( this->m_value ) : 0 };
		}

		template <typename type>
		[[nodiscard]] type* as( ) const noexcept
		{
			return reinterpret_cast< type* >( this->m_value );
		}

	private:
		std::uintptr_t m_value{};
	};

	class dll
	{
	public:
		dll( ) = default;
		explicit dll( std::string_view name );

		[[nodiscard]] bool valid( ) const noexcept { return this->m_base != 0; }
		[[nodiscard]] std::uintptr_t base( ) const noexcept { return this->m_base; }
		[[nodiscard]] std::size_t size( ) const noexcept { return this->m_size; }

		[[nodiscard]] address find( std::string_view pattern ) const;
		[[nodiscard]] void* get_interface( std::string_view name ) const;

		template <typename type>
		[[nodiscard]] type* get_interface( std::string_view name ) const
		{
			return static_cast< type* >( this->get_interface( name ) );
		}

	private:
		std::uintptr_t m_base{};
		std::size_t m_size{};
	};

	struct modules
	{
		dll client{};
		dll render_system{};
		dll schema_system{};
		dll input_system{};
		dll tier0{};
		dll engine2{};
	};

	inline modules g_modules{};

	[[nodiscard]] bool load_modules( );

} // namespace opaline::core
