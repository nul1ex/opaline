#pragma once

#include <cstdint>

namespace opaline::sdk::offsets::client {

	namespace aabb_t {

		constexpr std::uint32_t m_vMinBounds{ 0x0 };
		constexpr std::uint32_t m_vMaxBounds{ 0xC };

	} // namespace aabb_t

	namespace activemodelconfig_t {

		constexpr std::uint32_t m_Handle{ 0x30 };
		constexpr std::uint32_t m_Name{ 0x38 };
		constexpr std::uint32_t m_AssociatedEntities{ 0x40 };
		constexpr std::uint32_t m_AssociatedEntityNames{ 0x58 };

	} // namespace activemodelconfig_t

	namespace ammoindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace ammoindex_t

	namespace ammotypeinfo_t {

		constexpr std::uint32_t m_nMaxCarry{ 0x10 };
		constexpr std::uint32_t m_nSplashSize{ 0x1C };
		constexpr std::uint32_t m_nFlags{ 0x24 };
		constexpr std::uint32_t m_flMass{ 0x28 };
		constexpr std::uint32_t m_flSpeed{ 0x2C };

	} // namespace ammotypeinfo_t

	namespace audioparams_t {

		constexpr std::uint32_t localSound{ 0x8 };
		constexpr std::uint32_t soundscapeIndex{ 0x68 };
		constexpr std::uint32_t localBits{ 0x6C };
		constexpr std::uint32_t soundscapeEntityListIndex{ 0x70 };
		constexpr std::uint32_t soundEventHash{ 0x74 };

	} // namespace audioparams_t

	namespace c_attributecontainer {

		constexpr std::uint32_t m_Item{ 0x50 };
		constexpr std::uint32_t m_iExternalItemProviderRegisteredToken{ 0x4C0 };
		constexpr std::uint32_t m_ullRegisteredAsItemID{ 0x4C8 };

	} // namespace c_attributecontainer

	namespace c_barnlight {

		constexpr std::uint32_t m_bEnabled{ 0xE88 };
		constexpr std::uint32_t m_nColorMode{ 0xE8C };
		constexpr std::uint32_t m_Color{ 0xE90 };
		constexpr std::uint32_t m_flColorTemperature{ 0xE94 };
		constexpr std::uint32_t m_flBrightness{ 0xE98 };
		constexpr std::uint32_t m_flBrightnessScale{ 0xE9C };
		constexpr std::uint32_t m_nDirectLight{ 0xEA0 };
		constexpr std::uint32_t m_nBakedShadowIndex{ 0xEA4 };
		constexpr std::uint32_t m_nLightPathUniqueId{ 0xEA8 };
		constexpr std::uint32_t m_nLightMapUniqueId{ 0xEAC };
		constexpr std::uint32_t m_nLuminaireShape{ 0xEB0 };
		constexpr std::uint32_t m_flLuminaireSize{ 0xEB4 };
		constexpr std::uint32_t m_flLuminaireAnisotropy{ 0xEB8 };
		constexpr std::uint32_t m_LightStyleString{ 0xEC0 };
		constexpr std::uint32_t m_flLightStyleStartTime{ 0xEC8 };
		constexpr std::uint32_t m_QueuedLightStyleStrings{ 0xED0 };
		constexpr std::uint32_t m_LightStyleEvents{ 0xEE8 };
		constexpr std::uint32_t m_LightStyleTargets{ 0xF00 };
		constexpr std::uint32_t m_StyleEvent{ 0xF18 };
		constexpr std::uint32_t m_hLightCookie{ 0xF78 };
		constexpr std::uint32_t m_flShape{ 0xF80 };
		constexpr std::uint32_t m_flSoftX{ 0xF84 };
		constexpr std::uint32_t m_flSoftY{ 0xF88 };
		constexpr std::uint32_t m_flSkirt{ 0xF8C };
		constexpr std::uint32_t m_flSkirtNear{ 0xF90 };
		constexpr std::uint32_t m_vSizeParams{ 0xF94 };
		constexpr std::uint32_t m_flRange{ 0xFA0 };
		constexpr std::uint32_t m_vShear{ 0xFA4 };
		constexpr std::uint32_t m_nBakeSpecularToCubemaps{ 0xFB0 };
		constexpr std::uint32_t m_vBakeSpecularToCubemapsSize{ 0xFB4 };
		constexpr std::uint32_t m_nCastShadows{ 0xFC0 };
		constexpr std::uint32_t m_nShadowMapSize{ 0xFC4 };
		constexpr std::uint32_t m_nShadowPriority{ 0xFC8 };
		constexpr std::uint32_t m_bContactShadow{ 0xFCC };
		constexpr std::uint32_t m_bForceShadowsEnabled{ 0xFCD };
		constexpr std::uint32_t m_nBounceLight{ 0xFD0 };
		constexpr std::uint32_t m_flBounceScale{ 0xFD4 };
		constexpr std::uint32_t m_bDynamicBounce{ 0xFD8 };
		constexpr std::uint32_t m_flMinRoughness{ 0xFDC };
		constexpr std::uint32_t m_vAlternateColor{ 0xFE0 };
		constexpr std::uint32_t m_fAlternateColorBrightness{ 0xFEC };
		constexpr std::uint32_t m_nFog{ 0xFF0 };
		constexpr std::uint32_t m_flFogStrength{ 0xFF4 };
		constexpr std::uint32_t m_nFogShadows{ 0xFF8 };
		constexpr std::uint32_t m_flFogScale{ 0xFFC };
		constexpr std::uint32_t m_bFogMixedShadows{ 0x1000 };
		constexpr std::uint32_t m_flFadeSizeStart{ 0x1004 };
		constexpr std::uint32_t m_flFadeSizeEnd{ 0x1008 };
		constexpr std::uint32_t m_flShadowFadeSizeStart{ 0x100C };
		constexpr std::uint32_t m_flShadowFadeSizeEnd{ 0x1010 };
		constexpr std::uint32_t m_bPrecomputedFieldsValid{ 0x1014 };
		constexpr std::uint32_t m_vPrecomputedBoundsMins{ 0x1018 };
		constexpr std::uint32_t m_vPrecomputedBoundsMaxs{ 0x1024 };
		constexpr std::uint32_t m_vPrecomputedOBBOrigin{ 0x1030 };
		constexpr std::uint32_t m_vPrecomputedOBBAngles{ 0x103C };
		constexpr std::uint32_t m_vPrecomputedOBBExtent{ 0x1048 };
		constexpr std::uint32_t m_nPrecomputedSubFrusta{ 0x1054 };
		constexpr std::uint32_t m_vPrecomputedOBBOrigin0{ 0x1058 };
		constexpr std::uint32_t m_vPrecomputedOBBAngles0{ 0x1064 };
		constexpr std::uint32_t m_vPrecomputedOBBExtent0{ 0x1070 };
		constexpr std::uint32_t m_vPrecomputedOBBOrigin1{ 0x107C };
		constexpr std::uint32_t m_vPrecomputedOBBAngles1{ 0x1088 };
		constexpr std::uint32_t m_vPrecomputedOBBExtent1{ 0x1094 };
		constexpr std::uint32_t m_vPrecomputedOBBOrigin2{ 0x10A0 };
		constexpr std::uint32_t m_vPrecomputedOBBAngles2{ 0x10AC };
		constexpr std::uint32_t m_vPrecomputedOBBExtent2{ 0x10B8 };
		constexpr std::uint32_t m_vPrecomputedOBBOrigin3{ 0x10C4 };
		constexpr std::uint32_t m_vPrecomputedOBBAngles3{ 0x10D0 };
		constexpr std::uint32_t m_vPrecomputedOBBExtent3{ 0x10DC };
		constexpr std::uint32_t m_vPrecomputedOBBOrigin4{ 0x10E8 };
		constexpr std::uint32_t m_vPrecomputedOBBAngles4{ 0x10F4 };
		constexpr std::uint32_t m_vPrecomputedOBBExtent4{ 0x1100 };
		constexpr std::uint32_t m_vPrecomputedOBBOrigin5{ 0x110C };
		constexpr std::uint32_t m_vPrecomputedOBBAngles5{ 0x1118 };
		constexpr std::uint32_t m_vPrecomputedOBBExtent5{ 0x1124 };
		constexpr std::uint32_t m_bInitialBoneSetup{ 0x1170 };
		constexpr std::uint32_t m_VisClusters{ 0x1178 };

	} // namespace c_barnlight

	namespace c_basebutton {

		constexpr std::uint32_t m_glowEntity{ 0xE88 };
		constexpr std::uint32_t m_usable{ 0xE8C };
		constexpr std::uint32_t m_szDisplayText{ 0xE90 };

	} // namespace c_basebutton

	namespace c_baseclientuientity {

		constexpr std::uint32_t m_bEnabled{ 0xE90 };
		constexpr std::uint32_t m_DialogXMLName{ 0xE98 };
		constexpr std::uint32_t m_PanelClassName{ 0xEA0 };
		constexpr std::uint32_t m_PanelID{ 0xEA8 };

	} // namespace c_baseclientuientity

	namespace c_basecombatcharacter {

		constexpr std::uint32_t m_hMyWearables{ 0x1350 };
		constexpr std::uint32_t m_leftFootAttachment{ 0x1368 };
		constexpr std::uint32_t m_rightFootAttachment{ 0x1369 };
		constexpr std::uint32_t m_nWaterWakeMode{ 0x136C };
		constexpr std::uint32_t m_flWaterWorldZ{ 0x1370 };
		constexpr std::uint32_t m_flWaterNextTraceTime{ 0x1374 };

	} // namespace c_basecombatcharacter

	namespace c_basecsgrenade {

		constexpr std::uint32_t m_bClientPredictDelete{ 0x1F40 };
		constexpr std::uint32_t m_bRedraw{ 0x1F41 };
		constexpr std::uint32_t m_bIsHeldByPlayer{ 0x1F42 };
		constexpr std::uint32_t m_bPinPulled{ 0x1F43 };
		constexpr std::uint32_t m_bJumpThrow{ 0x1F44 };
		constexpr std::uint32_t m_bThrowAnimating{ 0x1F45 };
		constexpr std::uint32_t m_fThrowTime{ 0x1F48 };
		constexpr std::uint32_t m_flThrowStrength{ 0x1F50 };
		constexpr std::uint32_t m_fDropTime{ 0x1FC8 };
		constexpr std::uint32_t m_fPinPullTime{ 0x1FCC };
		constexpr std::uint32_t m_bJustPulledPin{ 0x1FD0 };
		constexpr std::uint32_t m_nNextHoldTick{ 0x1FD4 };
		constexpr std::uint32_t m_flNextHoldFrac{ 0x1FD8 };
		constexpr std::uint32_t m_hSwitchToWeaponAfterThrow{ 0x1FDC };

	} // namespace c_basecsgrenade

	namespace c_basecsgrenadeprojectile {

		constexpr std::uint32_t m_vInitialPosition{ 0x13A0 };
		constexpr std::uint32_t m_vInitialVelocity{ 0x13AC };
		constexpr std::uint32_t m_nBounces{ 0x13B8 };
		constexpr std::uint32_t m_nExplodeEffectIndex{ 0x13C0 };
		constexpr std::uint32_t m_nExplodeEffectTickBegin{ 0x13C8 };
		constexpr std::uint32_t m_vecExplodeEffectOrigin{ 0x13CC };
		constexpr std::uint32_t m_flSpawnTime{ 0x13D8 };
		constexpr std::uint32_t vecLastTrailLinePos{ 0x13DC };
		constexpr std::uint32_t flNextTrailLineTime{ 0x13E8 };
		constexpr std::uint32_t m_bExplodeEffectBegan{ 0x13EC };
		constexpr std::uint32_t m_bCanCreateGrenadeTrail{ 0x13ED };
		constexpr std::uint32_t m_nSnapshotTrajectoryEffectIndex{ 0x13F0 };
		constexpr std::uint32_t m_hSnapshotTrajectoryParticleSnapshot{ 0x13F8 };
		constexpr std::uint32_t m_arrTrajectoryTrailPoints{ 0x1400 };
		constexpr std::uint32_t m_arrTrajectoryTrailPointCreationTimes{ 0x1418 };
		constexpr std::uint32_t m_flTrajectoryTrailEffectCreationTime{ 0x1430 };

	} // namespace c_basecsgrenadeprojectile

	namespace c_basedoor {

		constexpr std::uint32_t m_bIsUsable{ 0xE88 };

	} // namespace c_basedoor

	namespace c_baseentity {

		constexpr std::uint32_t m_CBodyComponent{ 0x38 };
		constexpr std::uint32_t m_NetworkTransmitComponent{ 0x40 };
		constexpr std::uint32_t m_nLastThinkTick{ 0x330 };
		constexpr std::uint32_t m_pGameSceneNode{ 0x338 };
		constexpr std::uint32_t m_pRenderComponent{ 0x340 };
		constexpr std::uint32_t m_pCollision{ 0x348 };
		constexpr std::uint32_t m_iMaxHealth{ 0x350 };
		constexpr std::uint32_t m_iHealth{ 0x354 };
		constexpr std::uint32_t m_flDamageAccumulator{ 0x358 };
		constexpr std::uint32_t m_lifeState{ 0x35C };
		constexpr std::uint32_t m_bTakesDamage{ 0x35D };
		constexpr std::uint32_t m_nTakeDamageFlags{ 0x360 };
		constexpr std::uint32_t m_nPlatformType{ 0x368 };
		constexpr std::uint32_t m_ubInterpolationFrame{ 0x369 };
		constexpr std::uint32_t m_hSceneObjectController{ 0x36C };
		constexpr std::uint32_t m_nNoInterpolationTick{ 0x370 };
		constexpr std::uint32_t m_nVisibilityNoInterpolationTick{ 0x374 };
		constexpr std::uint32_t m_flProxyRandomValue{ 0x378 };
		constexpr std::uint32_t m_iEFlags{ 0x37C };
		constexpr std::uint32_t m_nWaterType{ 0x380 };
		constexpr std::uint32_t m_bInterpolateEvenWithNoModel{ 0x381 };
		constexpr std::uint32_t m_bPredictionEligible{ 0x382 };
		constexpr std::uint32_t m_bApplyLayerMatchIDToModel{ 0x383 };
		constexpr std::uint32_t m_tokLayerMatchID{ 0x384 };
		constexpr std::uint32_t m_nSubclassID{ 0x388 };
		constexpr std::uint32_t m_nSimulationTick{ 0x398 };
		constexpr std::uint32_t m_iCurrentThinkContext{ 0x39C };
		constexpr std::uint32_t m_aThinkFunctions{ 0x3A0 };
		constexpr std::uint32_t m_bDisabledContextThinks{ 0x3B8 };
		constexpr std::uint32_t m_flAnimTime{ 0x3BC };
		constexpr std::uint32_t m_flSimulationTime{ 0x3C0 };
		constexpr std::uint32_t m_nSceneObjectOverrideFlags{ 0x3C4 };
		constexpr std::uint32_t m_bHasSuccessfullyInterpolated{ 0x3C5 };
		constexpr std::uint32_t m_bHasAddedVarsToInterpolation{ 0x3C6 };
		constexpr std::uint32_t m_bRenderEvenWhenNotSuccessfullyInterpolated{ 0x3C7 };
		constexpr std::uint32_t m_nInterpolationLatchDirtyFlags{ 0x3C8 };
		constexpr std::uint32_t m_ListEntry{ 0x3D0 };
		constexpr std::uint32_t m_flCreateTime{ 0x3E8 };
		constexpr std::uint32_t m_flSpeed{ 0x3EC };
		constexpr std::uint32_t m_EntClientFlags{ 0x3F0 };
		constexpr std::uint32_t m_bClientSideRagdoll{ 0x3F2 };
		constexpr std::uint32_t m_iTeamNum{ 0x3F3 };
		constexpr std::uint32_t m_spawnflags{ 0x3F4 };
		constexpr std::uint32_t m_nNextThinkTick{ 0x3F8 };
		constexpr std::uint32_t m_fFlags{ 0x400 };
		constexpr std::uint32_t m_vecAbsVelocity{ 0x404 };
		constexpr std::uint32_t m_vecServerVelocity{ 0x410 };
		constexpr std::uint32_t m_vecVelocity{ 0x438 };
		constexpr std::uint32_t m_vecBaseVelocity{ 0x518 };
		constexpr std::uint32_t m_hEffectEntity{ 0x524 };
		constexpr std::uint32_t m_hOwnerEntity{ 0x528 };
		constexpr std::uint32_t m_MoveCollide{ 0x52C };
		constexpr std::uint32_t m_MoveType{ 0x52D };
		constexpr std::uint32_t m_nActualMoveType{ 0x52E };
		constexpr std::uint32_t m_flWaterLevel{ 0x530 };
		constexpr std::uint32_t m_fEffects{ 0x534 };
		constexpr std::uint32_t m_hGroundEntity{ 0x538 };
		constexpr std::uint32_t m_nGroundBodyIndex{ 0x53C };
		constexpr std::uint32_t m_flFriction{ 0x540 };
		constexpr std::uint32_t m_flElasticity{ 0x544 };
		constexpr std::uint32_t m_flGravityScale{ 0x548 };
		constexpr std::uint32_t m_flTimeScale{ 0x54C };
		constexpr std::uint32_t m_bAnimatedEveryTick{ 0x550 };
		constexpr std::uint32_t m_bGravityDisabled{ 0x551 };
		constexpr std::uint32_t m_flNavIgnoreUntilTime{ 0x554 };
		constexpr std::uint32_t m_hThink{ 0x558 };
		constexpr std::uint32_t m_fBBoxVisFlags{ 0x568 };
		constexpr std::uint32_t m_flActualGravityScale{ 0x56C };
		constexpr std::uint32_t m_bGravityActuallyDisabled{ 0x570 };
		constexpr std::uint32_t m_bPredictable{ 0x571 };
		constexpr std::uint32_t m_bRenderWithViewModels{ 0x572 };
		constexpr std::uint32_t m_nFirstPredictableCommand{ 0x574 };
		constexpr std::uint32_t m_nLastPredictableCommand{ 0x578 };
		constexpr std::uint32_t m_hOldMoveParent{ 0x57C };
		constexpr std::uint32_t m_Particles{ 0x580 };
		constexpr std::uint32_t m_vecAngVelocity{ 0x5B0 };
		constexpr std::uint32_t m_DataChangeEventRef{ 0x5BC };
		constexpr std::uint32_t m_dependencies{ 0x5C0 };
		constexpr std::uint32_t m_nCreationTick{ 0x5D8 };
		constexpr std::uint32_t m_bAnimTimeChanged{ 0x5E9 };
		constexpr std::uint32_t m_bSimulationTimeChanged{ 0x5EA };
		constexpr std::uint32_t m_sUniqueHammerID{ 0x5F8 };
		constexpr std::uint32_t m_nBloodType{ 0x600 };

	} // namespace c_baseentity

	namespace c_baseflex {

		constexpr std::uint32_t m_flexWeight{ 0x1170 };
		constexpr std::uint32_t m_vLookTargetPosition{ 0x1188 };
		constexpr std::uint32_t m_nLastFlexUpdateFrameCount{ 0x1270 };
		constexpr std::uint32_t m_CachedViewTarget{ 0x1274 };
		constexpr std::uint32_t m_nNextSceneEventId{ 0x1280 };
		constexpr std::uint32_t m_iMouthAttachment{ 0x1284 };
		constexpr std::uint32_t m_iEyeAttachment{ 0x1285 };
		constexpr std::uint32_t m_bResetFlexWeightsOnModelChange{ 0x1286 };
		constexpr std::uint32_t m_nEyeOcclusionRendererBone{ 0x12A0 };
		constexpr std::uint32_t m_mEyeOcclusionRendererCameraToBoneTransform{ 0x12A4 };
		constexpr std::uint32_t m_vEyeOcclusionRendererHalfExtent{ 0x12D4 };
		constexpr std::uint32_t m_PhonemeClasses{ 0x12F0 };

	} // namespace c_baseflex

	namespace c_baseflex__emphasized_phoneme {

		constexpr std::uint32_t m_sClassName{ 0x0 };
		constexpr std::uint32_t m_flAmount{ 0x18 };
		constexpr std::uint32_t m_bRequired{ 0x1C };
		constexpr std::uint32_t m_bBasechecked{ 0x1D };
		constexpr std::uint32_t m_bValid{ 0x1E };

	} // namespace c_baseflex__emphasized_phoneme

	namespace c_basegrenade {

		constexpr std::uint32_t m_bHasWarnedAI{ 0x1350 };
		constexpr std::uint32_t m_bIsSmokeGrenade{ 0x1351 };
		constexpr std::uint32_t m_bIsLive{ 0x1352 };
		constexpr std::uint32_t m_DmgRadius{ 0x1354 };
		constexpr std::uint32_t m_flDetonateTime{ 0x1358 };
		constexpr std::uint32_t m_flWarnAITime{ 0x135C };
		constexpr std::uint32_t m_flDamage{ 0x1360 };
		constexpr std::uint32_t m_iszBounceSound{ 0x1368 };
		constexpr std::uint32_t m_ExplosionSound{ 0x1370 };
		constexpr std::uint32_t m_hThrower{ 0x137C };
		constexpr std::uint32_t m_flNextAttack{ 0x1394 };
		constexpr std::uint32_t m_hOriginalThrower{ 0x1398 };

	} // namespace c_basegrenade

	namespace c_basemodelentity {

		constexpr std::uint32_t m_CRenderComponent{ 0xAF0 };
		constexpr std::uint32_t m_CHitboxComponent{ 0xAF8 };
		constexpr std::uint32_t m_nDestructiblePartInitialStateDestructed0{ 0xB10 };
		constexpr std::uint32_t m_nDestructiblePartInitialStateDestructed1{ 0xB14 };
		constexpr std::uint32_t m_nDestructiblePartInitialStateDestructed2{ 0xB18 };
		constexpr std::uint32_t m_nDestructiblePartInitialStateDestructed3{ 0xB1C };
		constexpr std::uint32_t m_nDestructiblePartInitialStateDestructed4{ 0xB20 };
		constexpr std::uint32_t m_nDestructiblePartInitialStateDestructed0_PartIndex{ 0xB24 };
		constexpr std::uint32_t m_nDestructiblePartInitialStateDestructed1_PartIndex{ 0xB28 };
		constexpr std::uint32_t m_nDestructiblePartInitialStateDestructed2_PartIndex{ 0xB2C };
		constexpr std::uint32_t m_nDestructiblePartInitialStateDestructed3_PartIndex{ 0xB30 };
		constexpr std::uint32_t m_nDestructiblePartInitialStateDestructed4_PartIndex{ 0xB34 };
		constexpr std::uint32_t m_pDestructiblePartsSystemComponent{ 0xB38 };
		constexpr std::uint32_t m_bInitModelEffects{ 0xB58 };
		constexpr std::uint32_t m_bDoingModelEffects{ 0xB59 };
		constexpr std::uint32_t m_bIsStaticProp{ 0xB5A };
		constexpr std::uint32_t m_iOldHealth{ 0xB5C };
		constexpr std::uint32_t m_nRenderMode{ 0xB60 };
		constexpr std::uint32_t m_nRenderFX{ 0xB61 };
		constexpr std::uint32_t m_bAllowFadeInView{ 0xB62 };
		constexpr std::uint32_t m_clrRender{ 0xB80 };
		constexpr std::uint32_t m_vecRenderAttributes{ 0xB88 };
		constexpr std::uint32_t m_bRenderToCubemaps{ 0xC08 };
		constexpr std::uint32_t m_bNoInterpolate{ 0xC09 };
		constexpr std::uint32_t m_Collision{ 0xC10 };
		constexpr std::uint32_t m_Glow{ 0xCC0 };
		constexpr std::uint32_t m_flGlowBackfaceMult{ 0xD18 };
		constexpr std::uint32_t m_fadeMinDist{ 0xD1C };
		constexpr std::uint32_t m_fadeMaxDist{ 0xD20 };
		constexpr std::uint32_t m_flFadeScale{ 0xD24 };
		constexpr std::uint32_t m_flShadowStrength{ 0xD28 };
		constexpr std::uint32_t m_nObjectCulling{ 0xD2C };
		constexpr std::uint32_t m_nRequiredDecalRtEncoding{ 0xD2D };
		constexpr std::uint32_t m_vecViewOffset{ 0xD58 };
		constexpr std::uint32_t m_pClientAlphaProperty{ 0xE38 };
		constexpr std::uint32_t m_ClientOverrideTint{ 0xE40 };
		constexpr std::uint32_t m_bUseClientOverrideTint{ 0xE44 };
		constexpr std::uint32_t m_bvDisabledHitGroups{ 0xE80 };

	} // namespace c_basemodelentity

	namespace c_baseplayerpawn {

		constexpr std::uint32_t m_pWeaponServices{ 0x13D8 };
		constexpr std::uint32_t m_pItemServices{ 0x13E0 };
		constexpr std::uint32_t m_pAutoaimServices{ 0x13E8 };
		constexpr std::uint32_t m_pObserverServices{ 0x13F0 };
		constexpr std::uint32_t m_pWaterServices{ 0x13F8 };
		constexpr std::uint32_t m_pUseServices{ 0x1400 };
		constexpr std::uint32_t m_pFlashlightServices{ 0x1408 };
		constexpr std::uint32_t m_pCameraServices{ 0x1410 };
		constexpr std::uint32_t m_pMovementServices{ 0x1418 };
		constexpr std::uint32_t m_ServerViewAngleChanges{ 0x1428 };
		constexpr std::uint32_t v_angle{ 0x1490 };
		constexpr std::uint32_t v_anglePrevious{ 0x149C };
		constexpr std::uint32_t m_iHideHUD{ 0x14A8 };
		constexpr std::uint32_t m_skybox3d{ 0x14B0 };
		constexpr std::uint32_t m_flDeathTime{ 0x1540 };
		constexpr std::uint32_t m_vecPredictionError{ 0x1544 };
		constexpr std::uint32_t m_flPredictionErrorTime{ 0x1550 };
		constexpr std::uint32_t m_vecLastCameraSetupLocalOrigin{ 0x1570 };
		constexpr std::uint32_t m_flLastCameraSetupTime{ 0x157C };
		constexpr std::uint32_t m_flFOVSensitivityAdjust{ 0x1580 };
		constexpr std::uint32_t m_flMouseSensitivity{ 0x1584 };
		constexpr std::uint32_t m_vOldOrigin{ 0x1588 };
		constexpr std::uint32_t m_flOldSimulationTime{ 0x1594 };
		constexpr std::uint32_t m_nLastExecutedCommandNumber{ 0x1598 };
		constexpr std::uint32_t m_nLastExecutedCommandTick{ 0x159C };
		constexpr std::uint32_t m_hController{ 0x15A0 };
		constexpr std::uint32_t m_hDefaultController{ 0x15A4 };
		constexpr std::uint32_t m_bIsSwappingToPredictableController{ 0x15A8 };

	} // namespace c_baseplayerpawn

	namespace c_baseplayerweapon {

		constexpr std::uint32_t m_nNextPrimaryAttackTick{ 0x18C0 };
		constexpr std::uint32_t m_flNextPrimaryAttackTickRatio{ 0x18C4 };
		constexpr std::uint32_t m_nNextSecondaryAttackTick{ 0x18C8 };
		constexpr std::uint32_t m_flNextSecondaryAttackTickRatio{ 0x18CC };
		constexpr std::uint32_t m_iClip1{ 0x18D0 };
		constexpr std::uint32_t m_iClip2{ 0x18D4 };
		constexpr std::uint32_t m_pReserveAmmo{ 0x18D8 };

	} // namespace c_baseplayerweapon

	namespace c_basepropdoor {

		constexpr std::uint32_t m_eDoorState{ 0x13B0 };
		constexpr std::uint32_t m_modelChanged{ 0x13B4 };
		constexpr std::uint32_t m_bLocked{ 0x13B5 };
		constexpr std::uint32_t m_bNoNPCs{ 0x13B6 };
		constexpr std::uint32_t m_closedPosition{ 0x13B8 };
		constexpr std::uint32_t m_closedAngles{ 0x13C4 };
		constexpr std::uint32_t m_hMaster{ 0x13D0 };
		constexpr std::uint32_t m_vWhereToSetLightingOrigin{ 0x13D4 };

	} // namespace c_basepropdoor

	namespace c_basetrigger {

		constexpr std::uint32_t m_OnStartTouch{ 0xE88 };
		constexpr std::uint32_t m_OnStartTouchAll{ 0xEA0 };
		constexpr std::uint32_t m_OnEndTouch{ 0xEB8 };
		constexpr std::uint32_t m_OnEndTouchAll{ 0xED0 };
		constexpr std::uint32_t m_OnTouching{ 0xEE8 };
		constexpr std::uint32_t m_OnTouchingEachEntity{ 0xF00 };
		constexpr std::uint32_t m_OnNotTouching{ 0xF18 };
		constexpr std::uint32_t m_hTouchingEntities{ 0xF30 };
		constexpr std::uint32_t m_iFilterName{ 0xF48 };
		constexpr std::uint32_t m_hFilter{ 0xF50 };
		constexpr std::uint32_t m_bDisabled{ 0xF54 };

	} // namespace c_basetrigger

	namespace c_beam {

		constexpr std::uint32_t m_flFrameRate{ 0xE88 };
		constexpr std::uint32_t m_flHDRColorScale{ 0xE8C };
		constexpr std::uint32_t m_flFireTime{ 0xE90 };
		constexpr std::uint32_t m_flDamage{ 0xE94 };
		constexpr std::uint32_t m_nNumBeamEnts{ 0xE98 };
		constexpr std::uint32_t m_queryHandleHalo{ 0xE9C };
		constexpr std::uint32_t m_hBaseMaterial{ 0xEC0 };
		constexpr std::uint32_t m_nHaloIndex{ 0xEC8 };
		constexpr std::uint32_t m_nBeamType{ 0xED0 };
		constexpr std::uint32_t m_nBeamFlags{ 0xED4 };
		constexpr std::uint32_t m_hAttachEntity{ 0xED8 };
		constexpr std::uint32_t m_nAttachIndex{ 0xF00 };
		constexpr std::uint32_t m_fWidth{ 0xF0C };
		constexpr std::uint32_t m_fEndWidth{ 0xF10 };
		constexpr std::uint32_t m_fFadeLength{ 0xF14 };
		constexpr std::uint32_t m_fHaloScale{ 0xF18 };
		constexpr std::uint32_t m_fAmplitude{ 0xF1C };
		constexpr std::uint32_t m_fStartFrame{ 0xF20 };
		constexpr std::uint32_t m_fSpeed{ 0xF24 };
		constexpr std::uint32_t m_flFrame{ 0xF28 };
		constexpr std::uint32_t m_nClipStyle{ 0xF2C };
		constexpr std::uint32_t m_bTurnedOff{ 0xF30 };
		constexpr std::uint32_t m_vecEndPos{ 0xF34 };
		constexpr std::uint32_t m_hEndEntity{ 0xF40 };

	} // namespace c_beam

	namespace c_breakableprop {

		constexpr std::uint32_t m_CPropDataComponent{ 0x11A0 };
		constexpr std::uint32_t m_OnStartDeath{ 0x11E0 };
		constexpr std::uint32_t m_OnBreak{ 0x11F8 };
		constexpr std::uint32_t m_OnHealthChanged{ 0x1210 };
		constexpr std::uint32_t m_OnTakeDamage{ 0x1230 };
		constexpr std::uint32_t m_impactEnergyScale{ 0x1248 };
		constexpr std::uint32_t m_iMinHealthDmg{ 0x124C };
		constexpr std::uint32_t m_flPressureDelay{ 0x1250 };
		constexpr std::uint32_t m_flDefBurstScale{ 0x1254 };
		constexpr std::uint32_t m_vDefBurstOffset{ 0x1258 };
		constexpr std::uint32_t m_hBreaker{ 0x1264 };
		constexpr std::uint32_t m_PerformanceMode{ 0x1268 };
		constexpr std::uint32_t m_flPreventDamageBeforeTime{ 0x126C };
		constexpr std::uint32_t m_BreakableContentsType{ 0x1270 };
		constexpr std::uint32_t m_strBreakableContentsPropGroupOverride{ 0x1278 };
		constexpr std::uint32_t m_strBreakableContentsParticleOverride{ 0x1280 };
		constexpr std::uint32_t m_bHasBreakPiecesOrCommands{ 0x1288 };
		constexpr std::uint32_t m_explodeDamage{ 0x128C };
		constexpr std::uint32_t m_explodeRadius{ 0x1290 };
		constexpr std::uint32_t m_nExplosionType{ 0x1294 };
		constexpr std::uint32_t m_explosionDelay{ 0x1298 };
		constexpr std::uint32_t m_explosionBuildupSound{ 0x12A0 };
		constexpr std::uint32_t m_explosionCustomEffect{ 0x12A8 };
		constexpr std::uint32_t m_explosionCustomSound{ 0x12B0 };
		constexpr std::uint32_t m_explosionModifier{ 0x12B8 };
		constexpr std::uint32_t m_hPhysicsAttacker{ 0x12C0 };
		constexpr std::uint32_t m_flLastPhysicsInfluenceTime{ 0x12C4 };
		constexpr std::uint32_t m_flDefaultFadeScale{ 0x12C8 };
		constexpr std::uint32_t m_hLastAttacker{ 0x12CC };

	} // namespace c_breakableprop

	namespace c_bullethitmodel {

		constexpr std::uint32_t m_matLocal{ 0x1168 };
		constexpr std::uint32_t m_iBoneIndex{ 0x1198 };
		constexpr std::uint32_t m_hPlayerParent{ 0x119C };
		constexpr std::uint32_t m_bIsHit{ 0x11A0 };
		constexpr std::uint32_t m_flTimeCreated{ 0x11A4 };
		constexpr std::uint32_t m_vecStartPos{ 0x11A8 };

	} // namespace c_bullethitmodel

	namespace c_c4 {

		constexpr std::uint32_t m_activeLightParticleIndex{ 0x1F40 };
		constexpr std::uint32_t m_eActiveLightEffect{ 0x1F44 };
		constexpr std::uint32_t m_bStartedArming{ 0x1F48 };
		constexpr std::uint32_t m_fArmedTime{ 0x1F4C };
		constexpr std::uint32_t m_bBombPlacedAnimation{ 0x1F50 };
		constexpr std::uint32_t m_bIsPlantingViaUse{ 0x1F51 };
		constexpr std::uint32_t m_entitySpottedState{ 0x1F58 };
		constexpr std::uint32_t m_nSpotRules{ 0x1F70 };
		constexpr std::uint32_t m_bPlayedArmingBeeps{ 0x1F74 };
		constexpr std::uint32_t m_bBombPlanted{ 0x1F7B };

	} // namespace c_c4

	namespace c_chicken {

		constexpr std::uint32_t m_hHolidayHatAddon{ 0x13A8 };
		constexpr std::uint32_t m_jumpedThisFrame{ 0x13AC };
		constexpr std::uint32_t m_leader{ 0x13B0 };
		constexpr std::uint32_t m_AttributeManager{ 0x13B8 };
		constexpr std::uint32_t m_bAttributesInitialized{ 0x1888 };
		constexpr std::uint32_t m_hWaterWakeParticles{ 0x188C };
		constexpr std::uint32_t m_bIsPreviewModel{ 0x1890 };

	} // namespace c_chicken

	namespace c_clientragdoll {

		constexpr std::uint32_t m_bFadeOut{ 0x1168 };
		constexpr std::uint32_t m_bImportant{ 0x1169 };
		constexpr std::uint32_t m_flEffectTime{ 0x116C };
		constexpr std::uint32_t m_gibDespawnTime{ 0x1170 };
		constexpr std::uint32_t m_iCurrentFriction{ 0x1174 };
		constexpr std::uint32_t m_iMinFriction{ 0x1178 };
		constexpr std::uint32_t m_iMaxFriction{ 0x117C };
		constexpr std::uint32_t m_iFrictionAnimState{ 0x1180 };
		constexpr std::uint32_t m_bReleaseRagdoll{ 0x1184 };
		constexpr std::uint32_t m_iEyeAttachment{ 0x1185 };
		constexpr std::uint32_t m_bFadingOut{ 0x1186 };
		constexpr std::uint32_t m_flScaleEnd{ 0x1188 };
		constexpr std::uint32_t m_flScaleTimeStart{ 0x11B0 };
		constexpr std::uint32_t m_flScaleTimeEnd{ 0x11D8 };

	} // namespace c_clientragdoll

	namespace c_colorcorrection {

		constexpr std::uint32_t m_vecOrigin{ 0x608 };
		constexpr std::uint32_t m_MinFalloff{ 0x614 };
		constexpr std::uint32_t m_MaxFalloff{ 0x618 };
		constexpr std::uint32_t m_flFadeInDuration{ 0x61C };
		constexpr std::uint32_t m_flFadeOutDuration{ 0x620 };
		constexpr std::uint32_t m_flMaxWeight{ 0x624 };
		constexpr std::uint32_t m_flCurWeight{ 0x628 };
		constexpr std::uint32_t m_netlookupFilename{ 0x62C };
		constexpr std::uint32_t m_bEnabled{ 0x82C };
		constexpr std::uint32_t m_bMaster{ 0x82D };
		constexpr std::uint32_t m_bClientSide{ 0x82E };
		constexpr std::uint32_t m_bExclusive{ 0x82F };
		constexpr std::uint32_t m_bEnabledOnClient{ 0x830 };
		constexpr std::uint32_t m_flCurWeightOnClient{ 0x834 };
		constexpr std::uint32_t m_bFadingIn{ 0x838 };
		constexpr std::uint32_t m_flFadeStartWeight{ 0x83C };
		constexpr std::uint32_t m_flFadeStartTime{ 0x840 };
		constexpr std::uint32_t m_flFadeDuration{ 0x844 };

	} // namespace c_colorcorrection

	namespace c_colorcorrectionvolume {

		constexpr std::uint32_t m_LastEnterWeight{ 0xF58 };
		constexpr std::uint32_t m_LastEnterTime{ 0xF5C };
		constexpr std::uint32_t m_LastExitWeight{ 0xF60 };
		constexpr std::uint32_t m_LastExitTime{ 0xF64 };
		constexpr std::uint32_t m_bEnabled{ 0xF68 };
		constexpr std::uint32_t m_MaxWeight{ 0xF6C };
		constexpr std::uint32_t m_FadeDuration{ 0xF70 };
		constexpr std::uint32_t m_Weight{ 0xF74 };
		constexpr std::uint32_t m_lookupFilename{ 0xF78 };

	} // namespace c_colorcorrectionvolume

	namespace c_commandcontext {

		constexpr std::uint32_t needsprocessing{ 0x0 };
		constexpr std::uint32_t command_number{ 0xA0 };

	} // namespace c_commandcontext

	namespace c_csgamerules {

		constexpr std::uint32_t m_bFreezePeriod{ 0x40 };
		constexpr std::uint32_t m_bWarmupPeriod{ 0x41 };
		constexpr std::uint32_t m_fWarmupPeriodEnd{ 0x44 };
		constexpr std::uint32_t m_fWarmupPeriodStart{ 0x48 };
		constexpr std::uint32_t m_bTerroristTimeOutActive{ 0x4C };
		constexpr std::uint32_t m_bCTTimeOutActive{ 0x4D };
		constexpr std::uint32_t m_flTerroristTimeOutRemaining{ 0x50 };
		constexpr std::uint32_t m_flCTTimeOutRemaining{ 0x54 };
		constexpr std::uint32_t m_nTerroristTimeOuts{ 0x58 };
		constexpr std::uint32_t m_nCTTimeOuts{ 0x5C };
		constexpr std::uint32_t m_bTechnicalTimeOut{ 0x60 };
		constexpr std::uint32_t m_bMatchWaitingForResume{ 0x61 };
		constexpr std::uint32_t m_iFreezeTime{ 0x64 };
		constexpr std::uint32_t m_iRoundTime{ 0x68 };
		constexpr std::uint32_t m_fMatchStartTime{ 0x6C };
		constexpr std::uint32_t m_fRoundStartTime{ 0x70 };
		constexpr std::uint32_t m_flRestartRoundTime{ 0x74 };
		constexpr std::uint32_t m_bGameRestart{ 0x78 };
		constexpr std::uint32_t m_flGameStartTime{ 0x7C };
		constexpr std::uint32_t m_timeUntilNextPhaseStarts{ 0x80 };
		constexpr std::uint32_t m_gamePhase{ 0x84 };
		constexpr std::uint32_t m_totalRoundsPlayed{ 0x88 };
		constexpr std::uint32_t m_nRoundsPlayedThisPhase{ 0x8C };
		constexpr std::uint32_t m_nOvertimePlaying{ 0x90 };
		constexpr std::uint32_t m_iHostagesRemaining{ 0x94 };
		constexpr std::uint32_t m_bAnyHostageReached{ 0x98 };
		constexpr std::uint32_t m_bMapHasBombTarget{ 0x99 };
		constexpr std::uint32_t m_bMapHasRescueZone{ 0x9A };
		constexpr std::uint32_t m_bMapHasBuyZone{ 0x9B };
		constexpr std::uint32_t m_bIsQueuedMatchmaking{ 0x9C };
		constexpr std::uint32_t m_nQueuedMatchmakingMode{ 0xA0 };
		constexpr std::uint32_t m_bIsValveDS{ 0xA4 };
		constexpr std::uint32_t m_bLogoMap{ 0xA5 };
		constexpr std::uint32_t m_bPlayAllStepSoundsOnServer{ 0xA6 };
		constexpr std::uint32_t m_iSpectatorSlotCount{ 0xA8 };
		constexpr std::uint32_t m_MatchDevice{ 0xAC };
		constexpr std::uint32_t m_bHasMatchStarted{ 0xB0 };
		constexpr std::uint32_t m_nNextMapInMapgroup{ 0xB4 };
		constexpr std::uint32_t m_szTournamentEventName{ 0xB8 };
		constexpr std::uint32_t m_szTournamentEventStage{ 0x2B8 };
		constexpr std::uint32_t m_szMatchStatTxt{ 0x4B8 };
		constexpr std::uint32_t m_szTournamentPredictionsTxt{ 0x6B8 };
		constexpr std::uint32_t m_nTournamentPredictionsPct{ 0x8B8 };
		constexpr std::uint32_t m_flCMMItemDropRevealStartTime{ 0x8BC };
		constexpr std::uint32_t m_flCMMItemDropRevealEndTime{ 0x8C0 };
		constexpr std::uint32_t m_bIsDroppingItems{ 0x8C4 };
		constexpr std::uint32_t m_bIsQuestEligible{ 0x8C5 };
		constexpr std::uint32_t m_bIsHltvActive{ 0x8C6 };
		constexpr std::uint32_t m_bBombPlanted{ 0x8C7 };
		constexpr std::uint32_t m_arrProhibitedItemIndices{ 0x8C8 };
		constexpr std::uint32_t m_arrTournamentActiveCasterAccounts{ 0x990 };
		constexpr std::uint32_t m_numBestOfMaps{ 0x9A0 };
		constexpr std::uint32_t m_nHalloweenMaskListSeed{ 0x9A4 };
		constexpr std::uint32_t m_bBombDropped{ 0x9A8 };
		constexpr std::uint32_t m_iRoundWinStatus{ 0x9AC };
		constexpr std::uint32_t m_eRoundWinReason{ 0x9B0 };
		constexpr std::uint32_t m_bTCantBuy{ 0x9B4 };
		constexpr std::uint32_t m_bCTCantBuy{ 0x9B5 };
		constexpr std::uint32_t m_iMatchStats_RoundResults{ 0x9B8 };
		constexpr std::uint32_t m_iMatchStats_PlayersAlive_CT{ 0xA30 };
		constexpr std::uint32_t m_iMatchStats_PlayersAlive_T{ 0xAA8 };
		constexpr std::uint32_t m_TeamRespawnWaveTimes{ 0xB20 };
		constexpr std::uint32_t m_flNextRespawnWave{ 0xBA0 };
		constexpr std::uint32_t m_vMinimapMins{ 0xC20 };
		constexpr std::uint32_t m_vMinimapMaxs{ 0xC2C };
		constexpr std::uint32_t m_MinimapVerticalSectionHeights{ 0xC38 };
		constexpr std::uint32_t m_ullLocalMatchID{ 0xC58 };
		constexpr std::uint32_t m_nEndMatchMapGroupVoteTypes{ 0xC60 };
		constexpr std::uint32_t m_nEndMatchMapGroupVoteOptions{ 0xC88 };
		constexpr std::uint32_t m_nEndMatchMapVoteWinner{ 0xCB0 };
		constexpr std::uint32_t m_iNumConsecutiveCTLoses{ 0xCB4 };
		constexpr std::uint32_t m_iNumConsecutiveTerroristLoses{ 0xCB8 };
		constexpr std::uint32_t m_nMatchAbortedEarlyReason{ 0xD78 };
		constexpr std::uint32_t m_bHasTriggeredRoundStartMusic{ 0xD7C };
		constexpr std::uint32_t m_bSwitchingTeamsAtRoundReset{ 0xD7D };
		constexpr std::uint32_t m_pGameModeRules{ 0xD98 };
		constexpr std::uint32_t m_RetakeRules{ 0xDA0 };
		constexpr std::uint32_t m_nMatchEndCount{ 0xEF8 };
		constexpr std::uint32_t m_nTTeamIntroVariant{ 0xEFC };
		constexpr std::uint32_t m_nCTTeamIntroVariant{ 0xF00 };
		constexpr std::uint32_t m_bTeamIntroPeriod{ 0xF04 };
		constexpr std::uint32_t m_iRoundEndWinnerTeam{ 0xF08 };
		constexpr std::uint32_t m_eRoundEndReason{ 0xF0C };
		constexpr std::uint32_t m_bRoundEndShowTimerDefend{ 0xF10 };
		constexpr std::uint32_t m_iRoundEndTimerTime{ 0xF14 };
		constexpr std::uint32_t m_sRoundEndFunFactToken{ 0xF18 };
		constexpr std::uint32_t m_iRoundEndFunFactPlayerSlot{ 0xF20 };
		constexpr std::uint32_t m_iRoundEndFunFactData1{ 0xF24 };
		constexpr std::uint32_t m_iRoundEndFunFactData2{ 0xF28 };
		constexpr std::uint32_t m_iRoundEndFunFactData3{ 0xF2C };
		constexpr std::uint32_t m_sRoundEndMessage{ 0xF30 };
		constexpr std::uint32_t m_iRoundEndPlayerCount{ 0xF38 };
		constexpr std::uint32_t m_bRoundEndNoMusic{ 0xF3C };
		constexpr std::uint32_t m_iRoundEndLegacy{ 0xF40 };
		constexpr std::uint32_t m_nRoundEndCount{ 0xF44 };
		constexpr std::uint32_t m_iRoundStartRoundNumber{ 0xF48 };
		constexpr std::uint32_t m_nRoundStartCount{ 0xF4C };
		constexpr std::uint32_t m_flLastPerfSampleTime{ 0x4F58 };

	} // namespace c_csgamerules

	namespace c_csgamerulesproxy {

		constexpr std::uint32_t m_pGameRules{ 0x608 };

	} // namespace c_csgamerulesproxy

	namespace c_csgo_mappreviewcamerapath {

		constexpr std::uint32_t m_flZFar{ 0x608 };
		constexpr std::uint32_t m_flZNear{ 0x60C };
		constexpr std::uint32_t m_bLoop{ 0x610 };
		constexpr std::uint32_t m_bVerticalFOV{ 0x611 };
		constexpr std::uint32_t m_bConstantSpeed{ 0x612 };
		constexpr std::uint32_t m_flDuration{ 0x614 };
		constexpr std::uint32_t m_flPathLength{ 0x658 };
		constexpr std::uint32_t m_flPathDuration{ 0x65C };
		constexpr std::uint32_t m_bDofEnabled{ 0x674 };
		constexpr std::uint32_t m_flDofNearBlurry{ 0x678 };
		constexpr std::uint32_t m_flDofNearCrisp{ 0x67C };
		constexpr std::uint32_t m_flDofFarCrisp{ 0x680 };
		constexpr std::uint32_t m_flDofFarBlurry{ 0x684 };
		constexpr std::uint32_t m_flDofTiltToGround{ 0x688 };

	} // namespace c_csgo_mappreviewcamerapath

	namespace c_csgo_mappreviewcamerapathnode {

		constexpr std::uint32_t m_szParentPathUniqueID{ 0x608 };
		constexpr std::uint32_t m_nPathIndex{ 0x610 };
		constexpr std::uint32_t m_vInTangentLocal{ 0x614 };
		constexpr std::uint32_t m_vOutTangentLocal{ 0x620 };
		constexpr std::uint32_t m_flFOV{ 0x62C };
		constexpr std::uint32_t m_flCameraSpeed{ 0x630 };
		constexpr std::uint32_t m_flEaseIn{ 0x634 };
		constexpr std::uint32_t m_flEaseOut{ 0x638 };
		constexpr std::uint32_t m_vInTangentWorld{ 0x63C };
		constexpr std::uint32_t m_vOutTangentWorld{ 0x648 };

	} // namespace c_csgo_mappreviewcamerapathnode

	namespace c_csgo_previewmodel {

		constexpr std::uint32_t m_defaultAnim{ 0x1350 };
		constexpr std::uint32_t m_nDefaultAnimLoopMode{ 0x1358 };
		constexpr std::uint32_t m_flInitialModelScale{ 0x135C };
		constexpr std::uint32_t m_sInitialWeaponState{ 0x1360 };

	} // namespace c_csgo_previewmodel

	namespace c_csgo_previewplayer {

		constexpr std::uint32_t m_animgraphCharacterModeString{ 0x3EF0 };
		constexpr std::uint32_t m_flInitialModelScale{ 0x3EF8 };

	} // namespace c_csgo_previewplayer

	namespace c_csgo_previewplayer_graphcontroller {

		constexpr std::uint32_t m_pszCharacterMode{ 0x90 };
		constexpr std::uint32_t m_pszTeamPreviewVariant{ 0xC0 };
		constexpr std::uint32_t m_pszTeamPreviewPosition{ 0xF0 };
		constexpr std::uint32_t m_pszEndOfMatchCelebration{ 0x120 };
		constexpr std::uint32_t m_nTeamPreviewRandom{ 0x150 };
		constexpr std::uint32_t m_pszWeaponState{ 0x178 };
		constexpr std::uint32_t m_pszWeaponType{ 0x1A8 };
		constexpr std::uint32_t m_bCT{ 0x1D8 };

	} // namespace c_csgo_previewplayer_graphcontroller

	namespace c_csgo_teampreviewcamera {

		constexpr std::uint32_t m_nVariant{ 0x690 };

	} // namespace c_csgo_teampreviewcamera

	namespace c_csgo_teampreviewcharacterposition {

		constexpr std::uint32_t m_nVariant{ 0x608 };
		constexpr std::uint32_t m_nRandom{ 0x60C };
		constexpr std::uint32_t m_nOrdinal{ 0x610 };
		constexpr std::uint32_t m_sWeaponName{ 0x618 };
		constexpr std::uint32_t m_xuid{ 0x620 };
		constexpr std::uint32_t m_agentItem{ 0x628 };
		constexpr std::uint32_t m_glovesItem{ 0xA98 };
		constexpr std::uint32_t m_weaponItem{ 0xF08 };

	} // namespace c_csgo_teampreviewcharacterposition

	namespace c_csmfovoverride {

		constexpr std::uint32_t m_cameraName{ 0x608 };
		constexpr std::uint32_t m_flCsmFovOverrideValue{ 0x610 };

	} // namespace c_csmfovoverride

	namespace c_csobserverpawn {

		constexpr std::uint32_t m_hDetectParentChange{ 0x1650 };

	} // namespace c_csobserverpawn

	namespace c_csplayerpawn {

		constexpr std::uint32_t m_pBulletServices{ 0x1660 };
		constexpr std::uint32_t m_pHostageServices{ 0x1668 };
		constexpr std::uint32_t m_pBuyServices{ 0x1670 };
		constexpr std::uint32_t m_pGlowServices{ 0x1678 };
		constexpr std::uint32_t m_pActionTrackingServices{ 0x1680 };
		constexpr std::uint32_t m_pDamageReactServices{ 0x1688 };
		constexpr std::uint32_t m_flHealthShotBoostExpirationTime{ 0x1690 };
		constexpr std::uint32_t m_flLastFiredWeaponTime{ 0x1694 };
		constexpr std::uint32_t m_bHasFemaleVoice{ 0x1698 };
		constexpr std::uint32_t m_flLandingTimeSeconds{ 0x169C };
		constexpr std::uint32_t m_flOldFallVelocity{ 0x16A0 };
		constexpr std::uint32_t m_szLastPlaceName{ 0x16A4 };
		constexpr std::uint32_t m_bPrevDefuser{ 0x16B6 };
		constexpr std::uint32_t m_bPrevHelmet{ 0x16B7 };
		constexpr std::uint32_t m_nPrevArmorVal{ 0x16B8 };
		constexpr std::uint32_t m_nPrevGrenadeAmmoCount{ 0x16BC };
		constexpr std::uint32_t m_unPreviousWeaponHash{ 0x16C0 };
		constexpr std::uint32_t m_unWeaponHash{ 0x16C4 };
		constexpr std::uint32_t m_bInBuyZone{ 0x16C8 };
		constexpr std::uint32_t m_bPreviouslyInBuyZone{ 0x16C9 };
		constexpr std::uint32_t m_aimPunchAngle{ 0x16CC };
		constexpr std::uint32_t m_aimPunchAngleVel{ 0x16D8 };
		constexpr std::uint32_t m_aimPunchTickBase{ 0x16E4 };
		constexpr std::uint32_t m_aimPunchTickFraction{ 0x16E8 };
		constexpr std::uint32_t m_bInLanding{ 0x1710 };
		constexpr std::uint32_t m_flLandingStartTime{ 0x1714 };
		constexpr std::uint32_t m_bInHostageRescueZone{ 0x1718 };
		constexpr std::uint32_t m_bInBombZone{ 0x1719 };
		constexpr std::uint32_t m_bIsBuyMenuOpen{ 0x171A };
		constexpr std::uint32_t m_flTimeOfLastInjury{ 0x171C };
		constexpr std::uint32_t m_flNextSprayDecalTime{ 0x1720 };
		constexpr std::uint32_t m_iRetakesOffering{ 0x1878 };
		constexpr std::uint32_t m_iRetakesOfferingCard{ 0x187C };
		constexpr std::uint32_t m_bRetakesHasDefuseKit{ 0x1880 };
		constexpr std::uint32_t m_bRetakesMVPLastRound{ 0x1881 };
		constexpr std::uint32_t m_iRetakesMVPBoostItem{ 0x1884 };
		constexpr std::uint32_t m_RetakesMVPBoostExtraUtility{ 0x1888 };
		constexpr std::uint32_t m_bNeedToReApplyGloves{ 0x188D };
		constexpr std::uint32_t m_EconGloves{ 0x1890 };
		constexpr std::uint32_t m_nEconGlovesChanged{ 0x1D00 };
		constexpr std::uint32_t m_bMustSyncRagdollState{ 0x1D01 };
		constexpr std::uint32_t m_nRagdollDamageBone{ 0x1D04 };
		constexpr std::uint32_t m_vRagdollDamageForce{ 0x1D08 };
		constexpr std::uint32_t m_vRagdollDamagePosition{ 0x1D14 };
		constexpr std::uint32_t m_szRagdollDamageWeaponName{ 0x1D20 };
		constexpr std::uint32_t m_bRagdollDamageHeadshot{ 0x1D60 };
		constexpr std::uint32_t m_vRagdollServerOrigin{ 0x1D64 };
		constexpr std::uint32_t m_lastLandTime{ 0x23E0 };
		constexpr std::uint32_t m_bOnGroundLastTick{ 0x23E4 };
		constexpr std::uint32_t m_hHudModelArms{ 0x2400 };
		constexpr std::uint32_t m_qDeathEyeAngles{ 0x2404 };
		constexpr std::uint32_t m_bSkipOneHeadConstraintUpdate{ 0x2410 };
		constexpr std::uint32_t m_bLeftHanded{ 0x2411 };
		constexpr std::uint32_t m_fSwitchedHandednessTime{ 0x2414 };
		constexpr std::uint32_t m_flViewmodelOffsetX{ 0x2418 };
		constexpr std::uint32_t m_flViewmodelOffsetY{ 0x241C };
		constexpr std::uint32_t m_flViewmodelOffsetZ{ 0x2420 };
		constexpr std::uint32_t m_flViewmodelFOV{ 0x2424 };
		constexpr std::uint32_t m_vecPlayerPatchEconIndices{ 0x2428 };
		constexpr std::uint32_t m_GunGameImmunityColor{ 0x2460 };
		constexpr std::uint32_t m_vecBulletHitModels{ 0x24B0 };
		constexpr std::uint32_t m_bIsWalking{ 0x24C8 };
		constexpr std::uint32_t m_thirdPersonHeading{ 0x24D0 };
		constexpr std::uint32_t m_flSlopeDropOffset{ 0x2560 };
		constexpr std::uint32_t m_flSlopeDropHeight{ 0x25D8 };
		constexpr std::uint32_t m_vHeadConstraintOffset{ 0x2650 };
		constexpr std::uint32_t m_entitySpottedState{ 0x26E0 };
		constexpr std::uint32_t m_bIsScoped{ 0x26F8 };
		constexpr std::uint32_t m_bResumeZoom{ 0x26F9 };
		constexpr std::uint32_t m_bIsDefusing{ 0x26FA };
		constexpr std::uint32_t m_bIsGrabbingHostage{ 0x26FB };
		constexpr std::uint32_t m_iBlockingUseActionInProgress{ 0x26FC };
		constexpr std::uint32_t m_flEmitSoundTime{ 0x2700 };
		constexpr std::uint32_t m_bInNoDefuseArea{ 0x2704 };
		constexpr std::uint32_t m_nWhichBombZone{ 0x2708 };
		constexpr std::uint32_t m_iShotsFired{ 0x270C };
		constexpr std::uint32_t m_flFlinchStack{ 0x2710 };
		constexpr std::uint32_t m_flVelocityModifier{ 0x2714 };
		constexpr std::uint32_t m_flHitHeading{ 0x2718 };
		constexpr std::uint32_t m_nHitBodyPart{ 0x271C };
		constexpr std::uint32_t m_bWaitForNoAttack{ 0x2720 };
		constexpr std::uint32_t m_ignoreLadderJumpTime{ 0x2724 };
		constexpr std::uint32_t m_bKilledByHeadshot{ 0x2729 };
		constexpr std::uint32_t m_ArmorValue{ 0x272C };
		constexpr std::uint32_t m_unCurrentEquipmentValue{ 0x2730 };
		constexpr std::uint32_t m_unRoundStartEquipmentValue{ 0x2732 };
		constexpr std::uint32_t m_unFreezetimeEndEquipmentValue{ 0x2734 };
		constexpr std::uint32_t m_nLastKillerIndex{ 0x2738 };
		constexpr std::uint32_t m_bOldIsScoped{ 0x273C };
		constexpr std::uint32_t m_bHasDeathInfo{ 0x273D };
		constexpr std::uint32_t m_flDeathInfoTime{ 0x2740 };
		constexpr std::uint32_t m_vecDeathInfoOrigin{ 0x2744 };
		constexpr std::uint32_t m_grenadeParameterStashTime{ 0x2754 };
		constexpr std::uint32_t m_bGrenadeParametersStashed{ 0x2758 };
		constexpr std::uint32_t m_angStashedShootAngles{ 0x275C };
		constexpr std::uint32_t m_vecStashedGrenadeThrowPosition{ 0x2768 };
		constexpr std::uint32_t m_vecStashedVelocity{ 0x2774 };
		constexpr std::uint32_t m_angShootAngleHistory{ 0x2780 };
		constexpr std::uint32_t m_vecThrowPositionHistory{ 0x2798 };
		constexpr std::uint32_t m_vecVelocityHistory{ 0x27B0 };
		constexpr std::uint32_t m_PredictedDamageTags{ 0x27C8 };
		constexpr std::uint32_t m_nPrevHighestReceivedDamageTagTick{ 0x2830 };
		constexpr std::uint32_t m_nHighestAppliedDamageTagTick{ 0x2834 };
		constexpr std::uint32_t m_bShouldAutobuyDMWeapons{ 0x3D6C };
		constexpr std::uint32_t m_fImmuneToGunGameDamageTime{ 0x3D70 };
		constexpr std::uint32_t m_bGunGameImmunity{ 0x3D74 };
		constexpr std::uint32_t m_fImmuneToGunGameDamageTimeLast{ 0x3D78 };
		constexpr std::uint32_t m_fMolotovDamageTime{ 0x3D7C };
		constexpr std::uint32_t m_vecLastAliveLocalVelocity{ 0x3D84 };
		constexpr std::uint32_t m_fRenderingClipPlane{ 0x3D90 };
		constexpr std::uint32_t m_nLastClipPlaneSetupFrame{ 0x3DA0 };
		constexpr std::uint32_t m_vecLastClipCameraPos{ 0x3DA4 };
		constexpr std::uint32_t m_vecLastClipCameraForward{ 0x3DB0 };
		constexpr std::uint32_t m_bClipHitStaticWorld{ 0x3DBC };
		constexpr std::uint32_t m_bCachedPlaneIsValid{ 0x3DBD };
		constexpr std::uint32_t m_pClippingWeapon{ 0x3DC0 };
		constexpr std::uint32_t m_nPlayerInfernoBodyFx{ 0x3DC8 };
		constexpr std::uint32_t m_angEyeAngles{ 0x3DD0 };
		constexpr std::uint32_t m_arrOldEyeAnglesTimes{ 0x3E60 };
		constexpr std::uint32_t m_arrOldEyeAngles{ 0x3E70 };
		constexpr std::uint32_t m_angEyeAnglesVelocity{ 0x3EA0 };
		constexpr std::uint32_t m_iIDEntIndex{ 0x3EAC };
		constexpr std::uint32_t m_delayTargetIDTimer{ 0x3EB0 };
		constexpr std::uint32_t m_iTargetItemEntIdx{ 0x3EC8 };
		constexpr std::uint32_t m_iOldIDEntIndex{ 0x3ECC };
		constexpr std::uint32_t m_holdTargetIDTimer{ 0x3ED0 };

	} // namespace c_csplayerpawn

	namespace c_csplayerpawnbase {

		constexpr std::uint32_t m_pPingServices{ 0x15C0 };
		constexpr std::uint32_t m_previousPlayerState{ 0x15C8 };
		constexpr std::uint32_t m_iPlayerState{ 0x15CC };
		constexpr std::uint32_t m_bHasMovedSinceSpawn{ 0x15D0 };
		constexpr std::uint32_t m_flLastSpawnTimeIndex{ 0x15D4 };
		constexpr std::uint32_t m_iProgressBarDuration{ 0x15D8 };
		constexpr std::uint32_t m_flProgressBarStartTime{ 0x15DC };
		constexpr std::uint32_t m_flClientDeathTime{ 0x15E0 };
		constexpr std::uint32_t m_flFlashBangTime{ 0x15E4 };
		constexpr std::uint32_t m_flFlashScreenshotAlpha{ 0x15E8 };
		constexpr std::uint32_t m_flFlashOverlayAlpha{ 0x15EC };
		constexpr std::uint32_t m_bFlashBuildUp{ 0x15F0 };
		constexpr std::uint32_t m_bFlashDspHasBeenCleared{ 0x15F1 };
		constexpr std::uint32_t m_bFlashScreenshotHasBeenGrabbed{ 0x15F2 };
		constexpr std::uint32_t m_flFlashMaxAlpha{ 0x15F4 };
		constexpr std::uint32_t m_flFlashDuration{ 0x15F8 };
		constexpr std::uint32_t m_flClientHealthFadeChangeTimestamp{ 0x15FC };
		constexpr std::uint32_t m_nClientHealthFadeParityValue{ 0x1600 };
		constexpr std::uint32_t m_fNextThinkPushAway{ 0x1604 };
		constexpr std::uint32_t m_flCurrentMusicStartTime{ 0x160C };
		constexpr std::uint32_t m_flMusicRoundStartTime{ 0x1610 };
		constexpr std::uint32_t m_bDeferStartMusicOnWarmup{ 0x1614 };
		constexpr std::uint32_t m_flLastSmokeOverlayAlpha{ 0x1618 };
		constexpr std::uint32_t m_flLastSmokeAge{ 0x161C };
		constexpr std::uint32_t m_vLastSmokeOverlayColor{ 0x1620 };
		constexpr std::uint32_t m_hOriginalController{ 0x1648 };

	} // namespace c_csplayerpawnbase

	namespace c_csplayerresource {

		constexpr std::uint32_t m_bHostageAlive{ 0x608 };
		constexpr std::uint32_t m_isHostageFollowingSomeone{ 0x614 };
		constexpr std::uint32_t m_iHostageEntityIDs{ 0x620 };
		constexpr std::uint32_t m_bombsiteCenterA{ 0x650 };
		constexpr std::uint32_t m_bombsiteCenterB{ 0x65C };
		constexpr std::uint32_t m_hostageRescueX{ 0x668 };
		constexpr std::uint32_t m_hostageRescueY{ 0x678 };
		constexpr std::uint32_t m_hostageRescueZ{ 0x688 };
		constexpr std::uint32_t m_bEndMatchNextMapAllVoted{ 0x698 };
		constexpr std::uint32_t m_foundGoalPositions{ 0x699 };

	} // namespace c_csplayerresource

	namespace c_csteam {

		constexpr std::uint32_t m_szTeamMatchStat{ 0x6C0 };
		constexpr std::uint32_t m_numMapVictories{ 0x8C0 };
		constexpr std::uint32_t m_bSurrendered{ 0x8C4 };
		constexpr std::uint32_t m_scoreFirstHalf{ 0x8C8 };
		constexpr std::uint32_t m_scoreSecondHalf{ 0x8CC };
		constexpr std::uint32_t m_scoreOvertime{ 0x8D0 };
		constexpr std::uint32_t m_szClanTeamname{ 0x8D4 };
		constexpr std::uint32_t m_iClanID{ 0x958 };
		constexpr std::uint32_t m_szTeamFlagImage{ 0x95C };
		constexpr std::uint32_t m_szTeamLogoImage{ 0x964 };

	} // namespace c_csteam

	namespace c_csweaponbase {

		constexpr std::uint32_t m_iWeaponGameplayAnimState{ 0x1948 };
		constexpr std::uint32_t m_flWeaponGameplayAnimStateTimestamp{ 0x194C };
		constexpr std::uint32_t m_flInspectCancelCompleteTime{ 0x1950 };
		constexpr std::uint32_t m_bInspectPending{ 0x1954 };
		constexpr std::uint32_t m_bInspectShouldLoop{ 0x1955 };
		constexpr std::uint32_t m_flCrosshairDistance{ 0x1980 };
		constexpr std::uint32_t m_iAmmoLastCheck{ 0x1984 };
		constexpr std::uint32_t m_nLastEmptySoundCmdNum{ 0x1988 };
		constexpr std::uint32_t m_bFireOnEmpty{ 0x198C };
		constexpr std::uint32_t m_OnPlayerPickup{ 0x1990 };
		constexpr std::uint32_t m_weaponMode{ 0x19A8 };
		constexpr std::uint32_t m_flTurningInaccuracyDelta{ 0x19AC };
		constexpr std::uint32_t m_vecTurningInaccuracyEyeDirLast{ 0x19B0 };
		constexpr std::uint32_t m_flTurningInaccuracy{ 0x19BC };
		constexpr std::uint32_t m_fAccuracyPenalty{ 0x19C0 };
		constexpr std::uint32_t m_flLastAccuracyUpdateTime{ 0x19C4 };
		constexpr std::uint32_t m_fAccuracySmoothedForZoom{ 0x19C8 };
		constexpr std::uint32_t m_iRecoilIndex{ 0x19CC };
		constexpr std::uint32_t m_flRecoilIndex{ 0x19D0 };
		constexpr std::uint32_t m_bBurstMode{ 0x19D4 };
		constexpr std::uint32_t m_flLastBurstModeChangeTime{ 0x19D8 };
		constexpr std::uint32_t m_nPostponeFireReadyTicks{ 0x19DC };
		constexpr std::uint32_t m_flPostponeFireReadyFrac{ 0x19E0 };
		constexpr std::uint32_t m_bInReload{ 0x19E4 };
		constexpr std::uint32_t m_flDroppedAtTime{ 0x19E8 };
		constexpr std::uint32_t m_bIsHauledBack{ 0x19EC };
		constexpr std::uint32_t m_bSilencerOn{ 0x19ED };
		constexpr std::uint32_t m_flTimeSilencerSwitchComplete{ 0x19F0 };
		constexpr std::uint32_t m_flWeaponActionPlaybackRate{ 0x19F4 };
		constexpr std::uint32_t m_iOriginalTeamNumber{ 0x19F8 };
		constexpr std::uint32_t m_iMostRecentTeamNumber{ 0x19FC };
		constexpr std::uint32_t m_bDroppedNearBuyZone{ 0x1A00 };
		constexpr std::uint32_t m_flNextAttackRenderTimeOffset{ 0x1A04 };
		constexpr std::uint32_t m_bClearWeaponIdentifyingUGC{ 0x1AA0 };
		constexpr std::uint32_t m_bVisualsDataSet{ 0x1AA1 };
		constexpr std::uint32_t m_bUIWeapon{ 0x1AA2 };
		constexpr std::uint32_t m_nCustomEconReloadEventId{ 0x1AA4 };
		constexpr std::uint32_t m_nextPrevOwnerUseTime{ 0x1AB0 };
		constexpr std::uint32_t m_hPrevOwner{ 0x1AB4 };
		constexpr std::uint32_t m_nDropTick{ 0x1AB8 };
		constexpr std::uint32_t m_bWasActiveWeaponWhenDropped{ 0x1ABC };
		constexpr std::uint32_t m_donated{ 0x1ADC };
		constexpr std::uint32_t m_fLastShotTime{ 0x1AE0 };
		constexpr std::uint32_t m_bWasOwnedByCT{ 0x1AE4 };
		constexpr std::uint32_t m_bWasOwnedByTerrorist{ 0x1AE5 };
		constexpr std::uint32_t m_flNextClientFireBulletTime{ 0x1AE8 };
		constexpr std::uint32_t m_flNextClientFireBulletTime_Repredict{ 0x1AEC };
		constexpr std::uint32_t m_IronSightController{ 0x1C50 };
		constexpr std::uint32_t m_iIronSightMode{ 0x1D00 };
		constexpr std::uint32_t m_flLastLOSTraceFailureTime{ 0x1D18 };
		constexpr std::uint32_t m_flWatTickOffset{ 0x1D78 };
		constexpr std::uint32_t m_flLastShakeTime{ 0x1D8C };

	} // namespace c_csweaponbase

	namespace c_csweaponbasegun {

		constexpr std::uint32_t m_zoomLevel{ 0x1F40 };
		constexpr std::uint32_t m_iBurstShotsRemaining{ 0x1F44 };
		constexpr std::uint32_t m_iSilencerBodygroup{ 0x1F48 };
		constexpr std::uint32_t m_silencedModelIndex{ 0x1F58 };
		constexpr std::uint32_t m_inPrecache{ 0x1F5C };
		constexpr std::uint32_t m_bNeedsBoltAction{ 0x1F5D };
		constexpr std::uint32_t m_nRevolverCylinderIdx{ 0x1F60 };

	} // namespace c_csweaponbasegun

	namespace c_decoyprojectile {

		constexpr std::uint32_t m_nDecoyShotTick{ 0x1438 };
		constexpr std::uint32_t m_nClientLastKnownDecoyShotTick{ 0x143C };
		constexpr std::uint32_t m_flTimeParticleEffectSpawn{ 0x1460 };

	} // namespace c_decoyprojectile

	namespace c_dynamiclight {

		constexpr std::uint32_t m_Flags{ 0xE88 };
		constexpr std::uint32_t m_LightStyle{ 0xE89 };
		constexpr std::uint32_t m_Radius{ 0xE8C };
		constexpr std::uint32_t m_Exponent{ 0xE90 };
		constexpr std::uint32_t m_InnerAngle{ 0xE94 };
		constexpr std::uint32_t m_OuterAngle{ 0xE98 };
		constexpr std::uint32_t m_SpotRadius{ 0xE9C };

	} // namespace c_dynamiclight

	namespace c_dynamicprop {

		constexpr std::uint32_t m_bUseHitboxesForRenderBox{ 0x12D0 };
		constexpr std::uint32_t m_bUseAnimGraph{ 0x12D1 };
		constexpr std::uint32_t m_pOutputAnimBegun{ 0x12D8 };
		constexpr std::uint32_t m_pOutputAnimOver{ 0x12F0 };
		constexpr std::uint32_t m_pOutputAnimLoopCycleOver{ 0x1308 };
		constexpr std::uint32_t m_OnAnimReachedStart{ 0x1320 };
		constexpr std::uint32_t m_OnAnimReachedEnd{ 0x1338 };
		constexpr std::uint32_t m_iszIdleAnim{ 0x1350 };
		constexpr std::uint32_t m_nIdleAnimLoopMode{ 0x1358 };
		constexpr std::uint32_t m_bRandomizeCycle{ 0x135C };
		constexpr std::uint32_t m_bStartDisabled{ 0x135D };
		constexpr std::uint32_t m_bFiredStartEndOutput{ 0x135E };
		constexpr std::uint32_t m_bForceNpcExclude{ 0x135F };
		constexpr std::uint32_t m_bCreateNonSolid{ 0x1360 };
		constexpr std::uint32_t m_bIsOverrideProp{ 0x1361 };
		constexpr std::uint32_t m_iInitialGlowState{ 0x1364 };
		constexpr std::uint32_t m_nGlowRange{ 0x1368 };
		constexpr std::uint32_t m_nGlowRangeMin{ 0x136C };
		constexpr std::uint32_t m_glowColor{ 0x1370 };
		constexpr std::uint32_t m_nGlowTeam{ 0x1374 };
		constexpr std::uint32_t m_iCachedFrameCount{ 0x1378 };
		constexpr std::uint32_t m_vecCachedRenderMins{ 0x137C };
		constexpr std::uint32_t m_vecCachedRenderMaxs{ 0x1388 };

	} // namespace c_dynamicprop

	namespace c_econentity {

		constexpr std::uint32_t m_flFlexDelayTime{ 0x1360 };
		constexpr std::uint32_t m_flFlexDelayedWeight{ 0x1368 };
		constexpr std::uint32_t m_bAttributesInitialized{ 0x1370 };
		constexpr std::uint32_t m_AttributeManager{ 0x1378 };
		constexpr std::uint32_t m_OriginalOwnerXuidLow{ 0x1848 };
		constexpr std::uint32_t m_OriginalOwnerXuidHigh{ 0x184C };
		constexpr std::uint32_t m_nFallbackPaintKit{ 0x1850 };
		constexpr std::uint32_t m_nFallbackSeed{ 0x1854 };
		constexpr std::uint32_t m_flFallbackWear{ 0x1858 };
		constexpr std::uint32_t m_nFallbackStatTrak{ 0x185C };
		constexpr std::uint32_t m_bClientside{ 0x1860 };
		constexpr std::uint32_t m_bParticleSystemsCreated{ 0x1861 };
		constexpr std::uint32_t m_vecAttachedParticles{ 0x1868 };
		constexpr std::uint32_t m_hViewmodelAttachment{ 0x1880 };
		constexpr std::uint32_t m_iOldTeam{ 0x1884 };
		constexpr std::uint32_t m_bAttachmentDirty{ 0x1888 };
		constexpr std::uint32_t m_nUnloadedModelIndex{ 0x188C };
		constexpr std::uint32_t m_iNumOwnerValidationRetries{ 0x1890 };
		constexpr std::uint32_t m_hOldProvidee{ 0x18A0 };
		constexpr std::uint32_t m_vecAttachedModels{ 0x18A8 };

	} // namespace c_econentity

	namespace c_econentity__attachedmodeldata_t {

		constexpr std::uint32_t m_iModelDisplayFlags{ 0x0 };

	} // namespace c_econentity__attachedmodeldata_t

	namespace c_econitemview {

		constexpr std::uint32_t m_bInventoryImageRgbaRequested{ 0x60 };
		constexpr std::uint32_t m_bInventoryImageTriedCache{ 0x61 };
		constexpr std::uint32_t m_nInventoryImageRgbaWidth{ 0x80 };
		constexpr std::uint32_t m_nInventoryImageRgbaHeight{ 0x84 };
		constexpr std::uint32_t m_szCurrentLoadCachedFileName{ 0x88 };
		constexpr std::uint32_t m_bRestoreCustomMaterialAfterPrecache{ 0x1B8 };
		constexpr std::uint32_t m_iItemDefinitionIndex{ 0x1BA };
		constexpr std::uint32_t m_iEntityQuality{ 0x1BC };
		constexpr std::uint32_t m_iEntityLevel{ 0x1C0 };
		constexpr std::uint32_t m_iItemID{ 0x1C8 };
		constexpr std::uint32_t m_iItemIDHigh{ 0x1D0 };
		constexpr std::uint32_t m_iItemIDLow{ 0x1D4 };
		constexpr std::uint32_t m_iAccountID{ 0x1D8 };
		constexpr std::uint32_t m_iInventoryPosition{ 0x1DC };
		constexpr std::uint32_t m_bInitialized{ 0x1E8 };
		constexpr std::uint32_t m_bDisallowSOC{ 0x1E9 };
		constexpr std::uint32_t m_bIsStoreItem{ 0x1EA };
		constexpr std::uint32_t m_bIsTradeItem{ 0x1EB };
		constexpr std::uint32_t m_iEntityQuantity{ 0x1EC };
		constexpr std::uint32_t m_iRarityOverride{ 0x1F0 };
		constexpr std::uint32_t m_iQualityOverride{ 0x1F4 };
		constexpr std::uint32_t m_iOriginOverride{ 0x1F8 };
		constexpr std::uint32_t m_ubStyleOverride{ 0x1FC };
		constexpr std::uint32_t m_unClientFlags{ 0x1FD };
		constexpr std::uint32_t m_AttributeList{ 0x208 };
		constexpr std::uint32_t m_NetworkedDynamicAttributes{ 0x280 };
		constexpr std::uint32_t m_szCustomName{ 0x2F8 };
		constexpr std::uint32_t m_szCustomNameOverride{ 0x399 };
		constexpr std::uint32_t m_bInitializedTags{ 0x468 };

	} // namespace c_econitemview

	namespace c_econwearable {

		constexpr std::uint32_t m_nForceSkin{ 0x18C0 };
		constexpr std::uint32_t m_bAlwaysAllow{ 0x18C4 };

	} // namespace c_econwearable

	namespace c_entitydissolve {

		constexpr std::uint32_t m_flStartTime{ 0xE90 };
		constexpr std::uint32_t m_flFadeInStart{ 0xE94 };
		constexpr std::uint32_t m_flFadeInLength{ 0xE98 };
		constexpr std::uint32_t m_flFadeOutModelStart{ 0xE9C };
		constexpr std::uint32_t m_flFadeOutModelLength{ 0xEA0 };
		constexpr std::uint32_t m_flFadeOutStart{ 0xEA4 };
		constexpr std::uint32_t m_flFadeOutLength{ 0xEA8 };
		constexpr std::uint32_t m_flNextSparkTime{ 0xEAC };
		constexpr std::uint32_t m_nDissolveType{ 0xEB0 };
		constexpr std::uint32_t m_vDissolverOrigin{ 0xEB4 };
		constexpr std::uint32_t m_nMagnitude{ 0xEC0 };
		constexpr std::uint32_t m_bCoreExplode{ 0xEC4 };
		constexpr std::uint32_t m_bLinkedToServerEnt{ 0xEC5 };

	} // namespace c_entitydissolve

	namespace c_entityflame {

		constexpr std::uint32_t m_hEntAttached{ 0x608 };
		constexpr std::uint32_t m_hOldAttached{ 0x630 };
		constexpr std::uint32_t m_bCheapEffect{ 0x634 };

	} // namespace c_entityflame

	namespace c_envcombinedlightprobevolume {

		constexpr std::uint32_t m_Entity_Color{ 0x1680 };
		constexpr std::uint32_t m_Entity_flBrightness{ 0x1684 };
		constexpr std::uint32_t m_Entity_hCubemapTexture{ 0x1688 };
		constexpr std::uint32_t m_Entity_bCustomCubemapTexture{ 0x1690 };
		constexpr std::uint32_t m_Entity_hLightProbeTexture_AmbientCube{ 0x1698 };
		constexpr std::uint32_t m_Entity_hLightProbeTexture_SDF{ 0x16A0 };
		constexpr std::uint32_t m_Entity_hLightProbeTexture_SH2_DC{ 0x16A8 };
		constexpr std::uint32_t m_Entity_hLightProbeTexture_SH2_R{ 0x16B0 };
		constexpr std::uint32_t m_Entity_hLightProbeTexture_SH2_G{ 0x16B8 };
		constexpr std::uint32_t m_Entity_hLightProbeTexture_SH2_B{ 0x16C0 };
		constexpr std::uint32_t m_Entity_hLightProbeDirectLightIndicesTexture{ 0x16C8 };
		constexpr std::uint32_t m_Entity_hLightProbeDirectLightScalarsTexture{ 0x16D0 };
		constexpr std::uint32_t m_Entity_hLightProbeDirectLightShadowsTexture{ 0x16D8 };
		constexpr std::uint32_t m_Entity_vBoxMins{ 0x16E0 };
		constexpr std::uint32_t m_Entity_vBoxMaxs{ 0x16EC };
		constexpr std::uint32_t m_Entity_bMoveable{ 0x16F8 };
		constexpr std::uint32_t m_Entity_nHandshake{ 0x16FC };
		constexpr std::uint32_t m_Entity_nEnvCubeMapArrayIndex{ 0x1700 };
		constexpr std::uint32_t m_Entity_nPriority{ 0x1704 };
		constexpr std::uint32_t m_Entity_bStartDisabled{ 0x1708 };
		constexpr std::uint32_t m_Entity_flEdgeFadeDist{ 0x170C };
		constexpr std::uint32_t m_Entity_vEdgeFadeDists{ 0x1710 };
		constexpr std::uint32_t m_Entity_nLightProbeSizeX{ 0x171C };
		constexpr std::uint32_t m_Entity_nLightProbeSizeY{ 0x1720 };
		constexpr std::uint32_t m_Entity_nLightProbeSizeZ{ 0x1724 };
		constexpr std::uint32_t m_Entity_nLightProbeAtlasX{ 0x1728 };
		constexpr std::uint32_t m_Entity_nLightProbeAtlasY{ 0x172C };
		constexpr std::uint32_t m_Entity_nLightProbeAtlasZ{ 0x1730 };
		constexpr std::uint32_t m_Entity_bEnabled{ 0x1749 };

	} // namespace c_envcombinedlightprobevolume

	namespace c_envcubemap {

		constexpr std::uint32_t m_Entity_hCubemapTexture{ 0x688 };
		constexpr std::uint32_t m_Entity_bCustomCubemapTexture{ 0x690 };
		constexpr std::uint32_t m_Entity_flInfluenceRadius{ 0x694 };
		constexpr std::uint32_t m_Entity_vBoxProjectMins{ 0x698 };
		constexpr std::uint32_t m_Entity_vBoxProjectMaxs{ 0x6A4 };
		constexpr std::uint32_t m_Entity_bMoveable{ 0x6B0 };
		constexpr std::uint32_t m_Entity_nHandshake{ 0x6B4 };
		constexpr std::uint32_t m_Entity_nEnvCubeMapArrayIndex{ 0x6B8 };
		constexpr std::uint32_t m_Entity_nPriority{ 0x6BC };
		constexpr std::uint32_t m_Entity_flEdgeFadeDist{ 0x6C0 };
		constexpr std::uint32_t m_Entity_vEdgeFadeDists{ 0x6C4 };
		constexpr std::uint32_t m_Entity_flDiffuseScale{ 0x6D0 };
		constexpr std::uint32_t m_Entity_bStartDisabled{ 0x6D4 };
		constexpr std::uint32_t m_Entity_bDefaultEnvMap{ 0x6D5 };
		constexpr std::uint32_t m_Entity_bDefaultSpecEnvMap{ 0x6D6 };
		constexpr std::uint32_t m_Entity_bIndoorCubeMap{ 0x6D7 };
		constexpr std::uint32_t m_Entity_bCopyDiffuseFromDefaultCubemap{ 0x6D8 };
		constexpr std::uint32_t m_Entity_bEnabled{ 0x6E8 };

	} // namespace c_envcubemap

	namespace c_envcubemapfog {

		constexpr std::uint32_t m_flEndDistance{ 0x608 };
		constexpr std::uint32_t m_flStartDistance{ 0x60C };
		constexpr std::uint32_t m_flFogFalloffExponent{ 0x610 };
		constexpr std::uint32_t m_bHeightFogEnabled{ 0x614 };
		constexpr std::uint32_t m_flFogHeightWidth{ 0x618 };
		constexpr std::uint32_t m_flFogHeightEnd{ 0x61C };
		constexpr std::uint32_t m_flFogHeightStart{ 0x620 };
		constexpr std::uint32_t m_flFogHeightExponent{ 0x624 };
		constexpr std::uint32_t m_flLODBias{ 0x628 };
		constexpr std::uint32_t m_bActive{ 0x62C };
		constexpr std::uint32_t m_bStartDisabled{ 0x62D };
		constexpr std::uint32_t m_flFogMaxOpacity{ 0x630 };
		constexpr std::uint32_t m_nCubemapSourceType{ 0x634 };
		constexpr std::uint32_t m_hSkyMaterial{ 0x638 };
		constexpr std::uint32_t m_iszSkyEntity{ 0x640 };
		constexpr std::uint32_t m_hFogCubemapTexture{ 0x648 };
		constexpr std::uint32_t m_bHasHeightFogEnd{ 0x650 };
		constexpr std::uint32_t m_bFirstTime{ 0x651 };

	} // namespace c_envcubemapfog

	namespace c_envdecal {

		constexpr std::uint32_t m_hDecalMaterial{ 0xE88 };
		constexpr std::uint32_t m_flWidth{ 0xE90 };
		constexpr std::uint32_t m_flHeight{ 0xE94 };
		constexpr std::uint32_t m_flDepth{ 0xE98 };
		constexpr std::uint32_t m_nRenderOrder{ 0xE9C };
		constexpr std::uint32_t m_bProjectOnWorld{ 0xEA0 };
		constexpr std::uint32_t m_bProjectOnCharacters{ 0xEA1 };
		constexpr std::uint32_t m_bProjectOnWater{ 0xEA2 };
		constexpr std::uint32_t m_flDepthSortBias{ 0xEA4 };

	} // namespace c_envdecal

	namespace c_envdetailcontroller {

		constexpr std::uint32_t m_flFadeStartDist{ 0x608 };
		constexpr std::uint32_t m_flFadeEndDist{ 0x60C };

	} // namespace c_envdetailcontroller

	namespace c_envlightprobevolume {

		constexpr std::uint32_t m_Entity_hLightProbeTexture_AmbientCube{ 0x1600 };
		constexpr std::uint32_t m_Entity_hLightProbeTexture_SDF{ 0x1608 };
		constexpr std::uint32_t m_Entity_hLightProbeTexture_SH2_DC{ 0x1610 };
		constexpr std::uint32_t m_Entity_hLightProbeTexture_SH2_R{ 0x1618 };
		constexpr std::uint32_t m_Entity_hLightProbeTexture_SH2_G{ 0x1620 };
		constexpr std::uint32_t m_Entity_hLightProbeTexture_SH2_B{ 0x1628 };
		constexpr std::uint32_t m_Entity_hLightProbeDirectLightIndicesTexture{ 0x1630 };
		constexpr std::uint32_t m_Entity_hLightProbeDirectLightScalarsTexture{ 0x1638 };
		constexpr std::uint32_t m_Entity_hLightProbeDirectLightShadowsTexture{ 0x1640 };
		constexpr std::uint32_t m_Entity_vBoxMins{ 0x1648 };
		constexpr std::uint32_t m_Entity_vBoxMaxs{ 0x1654 };
		constexpr std::uint32_t m_Entity_bMoveable{ 0x1660 };
		constexpr std::uint32_t m_Entity_nHandshake{ 0x1664 };
		constexpr std::uint32_t m_Entity_nPriority{ 0x1668 };
		constexpr std::uint32_t m_Entity_bStartDisabled{ 0x166C };
		constexpr std::uint32_t m_Entity_nLightProbeSizeX{ 0x1670 };
		constexpr std::uint32_t m_Entity_nLightProbeSizeY{ 0x1674 };
		constexpr std::uint32_t m_Entity_nLightProbeSizeZ{ 0x1678 };
		constexpr std::uint32_t m_Entity_nLightProbeAtlasX{ 0x167C };
		constexpr std::uint32_t m_Entity_nLightProbeAtlasY{ 0x1680 };
		constexpr std::uint32_t m_Entity_nLightProbeAtlasZ{ 0x1684 };
		constexpr std::uint32_t m_Entity_bEnabled{ 0x1691 };

	} // namespace c_envlightprobevolume

	namespace c_envparticleglow {

		constexpr std::uint32_t m_flAlphaScale{ 0x1438 };
		constexpr std::uint32_t m_flRadiusScale{ 0x143C };
		constexpr std::uint32_t m_flSelfIllumScale{ 0x1440 };
		constexpr std::uint32_t m_ColorTint{ 0x1444 };
		constexpr std::uint32_t m_hTextureOverride{ 0x1448 };

	} // namespace c_envparticleglow

	namespace c_envsky {

		constexpr std::uint32_t m_hSkyMaterial{ 0xE88 };
		constexpr std::uint32_t m_hSkyMaterialLightingOnly{ 0xE90 };
		constexpr std::uint32_t m_bStartDisabled{ 0xE98 };
		constexpr std::uint32_t m_vTintColor{ 0xE99 };
		constexpr std::uint32_t m_vTintColorLightingOnly{ 0xE9D };
		constexpr std::uint32_t m_flBrightnessScale{ 0xEA4 };
		constexpr std::uint32_t m_nFogType{ 0xEA8 };
		constexpr std::uint32_t m_flFogMinStart{ 0xEAC };
		constexpr std::uint32_t m_flFogMinEnd{ 0xEB0 };
		constexpr std::uint32_t m_flFogMaxStart{ 0xEB4 };
		constexpr std::uint32_t m_flFogMaxEnd{ 0xEB8 };
		constexpr std::uint32_t m_bEnabled{ 0xEBC };

	} // namespace c_envsky

	namespace c_envvolumetricfogcontroller {

		constexpr std::uint32_t m_flScattering{ 0x608 };
		constexpr std::uint32_t m_TintColor{ 0x60C };
		constexpr std::uint32_t m_flAnisotropy{ 0x610 };
		constexpr std::uint32_t m_flFadeSpeed{ 0x614 };
		constexpr std::uint32_t m_flDrawDistance{ 0x618 };
		constexpr std::uint32_t m_flFadeInStart{ 0x61C };
		constexpr std::uint32_t m_flFadeInEnd{ 0x620 };
		constexpr std::uint32_t m_flIndirectStrength{ 0x624 };
		constexpr std::uint32_t m_nVolumeDepth{ 0x628 };
		constexpr std::uint32_t m_fFirstVolumeSliceThickness{ 0x62C };
		constexpr std::uint32_t m_nIndirectTextureDimX{ 0x630 };
		constexpr std::uint32_t m_nIndirectTextureDimY{ 0x634 };
		constexpr std::uint32_t m_nIndirectTextureDimZ{ 0x638 };
		constexpr std::uint32_t m_vBoxMins{ 0x63C };
		constexpr std::uint32_t m_vBoxMaxs{ 0x648 };
		constexpr std::uint32_t m_bActive{ 0x654 };
		constexpr std::uint32_t m_flStartAnisoTime{ 0x658 };
		constexpr std::uint32_t m_flStartScatterTime{ 0x65C };
		constexpr std::uint32_t m_flStartDrawDistanceTime{ 0x660 };
		constexpr std::uint32_t m_flStartAnisotropy{ 0x664 };
		constexpr std::uint32_t m_flStartScattering{ 0x668 };
		constexpr std::uint32_t m_flStartDrawDistance{ 0x66C };
		constexpr std::uint32_t m_flDefaultAnisotropy{ 0x670 };
		constexpr std::uint32_t m_flDefaultScattering{ 0x674 };
		constexpr std::uint32_t m_flDefaultDrawDistance{ 0x678 };
		constexpr std::uint32_t m_bStartDisabled{ 0x67C };
		constexpr std::uint32_t m_bEnableIndirect{ 0x67D };
		constexpr std::uint32_t m_bIsMaster{ 0x67E };
		constexpr std::uint32_t m_hFogIndirectTexture{ 0x680 };
		constexpr std::uint32_t m_nForceRefreshCount{ 0x688 };
		constexpr std::uint32_t m_fNoiseSpeed{ 0x68C };
		constexpr std::uint32_t m_fNoiseStrength{ 0x690 };
		constexpr std::uint32_t m_vNoiseScale{ 0x694 };
		constexpr std::uint32_t m_fWindSpeed{ 0x6A0 };
		constexpr std::uint32_t m_vWindDirection{ 0x6A4 };
		constexpr std::uint32_t m_bFirstTime{ 0x6B0 };

	} // namespace c_envvolumetricfogcontroller

	namespace c_envvolumetricfogvolume {

		constexpr std::uint32_t m_bActive{ 0x608 };
		constexpr std::uint32_t m_vBoxMins{ 0x60C };
		constexpr std::uint32_t m_vBoxMaxs{ 0x618 };
		constexpr std::uint32_t m_bStartDisabled{ 0x624 };
		constexpr std::uint32_t m_bIndirectUseLPVs{ 0x625 };
		constexpr std::uint32_t m_flStrength{ 0x628 };
		constexpr std::uint32_t m_nFalloffShape{ 0x62C };
		constexpr std::uint32_t m_flFalloffExponent{ 0x630 };
		constexpr std::uint32_t m_flHeightFogDepth{ 0x634 };
		constexpr std::uint32_t m_fHeightFogEdgeWidth{ 0x638 };
		constexpr std::uint32_t m_fIndirectLightStrength{ 0x63C };
		constexpr std::uint32_t m_fSunLightStrength{ 0x640 };
		constexpr std::uint32_t m_fNoiseStrength{ 0x644 };
		constexpr std::uint32_t m_TintColor{ 0x648 };
		constexpr std::uint32_t m_bOverrideTintColor{ 0x64C };
		constexpr std::uint32_t m_bOverrideIndirectLightStrength{ 0x64D };
		constexpr std::uint32_t m_bOverrideSunLightStrength{ 0x64E };
		constexpr std::uint32_t m_bOverrideNoiseStrength{ 0x64F };

	} // namespace c_envvolumetricfogvolume

	namespace c_envwind {

		constexpr std::uint32_t m_EnvWindShared{ 0x608 };

	} // namespace c_envwind

	namespace c_envwindclientside {

		constexpr std::uint32_t m_EnvWindShared{ 0x608 };

	} // namespace c_envwindclientside

	namespace c_envwindcontroller {

		constexpr std::uint32_t m_EnvWindShared{ 0x608 };
		constexpr std::uint32_t m_fDirectionVariation{ 0x700 };
		constexpr std::uint32_t m_fSpeedVariation{ 0x704 };
		constexpr std::uint32_t m_fTurbulence{ 0x708 };
		constexpr std::uint32_t m_fVolumeHalfExtentXY{ 0x70C };
		constexpr std::uint32_t m_fVolumeHalfExtentZ{ 0x710 };
		constexpr std::uint32_t m_nVolumeResolutionXY{ 0x714 };
		constexpr std::uint32_t m_nVolumeResolutionZ{ 0x718 };
		constexpr std::uint32_t m_nClipmapLevels{ 0x71C };
		constexpr std::uint32_t m_bIsMaster{ 0x720 };
		constexpr std::uint32_t m_bFirstTime{ 0x721 };

	} // namespace c_envwindcontroller

	namespace c_envwindshared {

		constexpr std::uint32_t m_flStartTime{ 0x8 };
		constexpr std::uint32_t m_iWindSeed{ 0xC };
		constexpr std::uint32_t m_iMinWind{ 0x10 };
		constexpr std::uint32_t m_iMaxWind{ 0x12 };
		constexpr std::uint32_t m_windRadius{ 0x14 };
		constexpr std::uint32_t m_iMinGust{ 0x18 };
		constexpr std::uint32_t m_iMaxGust{ 0x1A };
		constexpr std::uint32_t m_flMinGustDelay{ 0x1C };
		constexpr std::uint32_t m_flMaxGustDelay{ 0x20 };
		constexpr std::uint32_t m_flGustDuration{ 0x24 };
		constexpr std::uint32_t m_iGustDirChange{ 0x28 };
		constexpr std::uint32_t m_iInitialWindDir{ 0x2A };
		constexpr std::uint32_t m_flInitialWindSpeed{ 0x2C };
		constexpr std::uint32_t m_location{ 0x30 };
		constexpr std::uint32_t m_hEntOwner{ 0x3C };

	} // namespace c_envwindshared

	namespace c_envwindvolume {

		constexpr std::uint32_t m_bActive{ 0x608 };
		constexpr std::uint32_t m_vBoxMins{ 0x60C };
		constexpr std::uint32_t m_vBoxMaxs{ 0x618 };
		constexpr std::uint32_t m_bStartDisabled{ 0x624 };
		constexpr std::uint32_t m_nShape{ 0x628 };
		constexpr std::uint32_t m_fWindSpeedMultiplier{ 0x62C };
		constexpr std::uint32_t m_fWindTurbulenceMultiplier{ 0x630 };
		constexpr std::uint32_t m_fWindSpeedVariationMultiplier{ 0x634 };
		constexpr std::uint32_t m_fWindDirectionVariationMultiplier{ 0x638 };

	} // namespace c_envwindvolume

	namespace c_fish {

		constexpr std::uint32_t m_pos{ 0x1168 };
		constexpr std::uint32_t m_vel{ 0x1174 };
		constexpr std::uint32_t m_angles{ 0x1180 };
		constexpr std::uint32_t m_localLifeState{ 0x118C };
		constexpr std::uint32_t m_deathDepth{ 0x1190 };
		constexpr std::uint32_t m_deathAngle{ 0x1194 };
		constexpr std::uint32_t m_buoyancy{ 0x1198 };
		constexpr std::uint32_t m_wiggleTimer{ 0x11A0 };
		constexpr std::uint32_t m_wigglePhase{ 0x11B8 };
		constexpr std::uint32_t m_wiggleRate{ 0x11BC };
		constexpr std::uint32_t m_actualPos{ 0x11C0 };
		constexpr std::uint32_t m_actualAngles{ 0x11CC };
		constexpr std::uint32_t m_poolOrigin{ 0x11D8 };
		constexpr std::uint32_t m_waterLevel{ 0x11E4 };
		constexpr std::uint32_t m_gotUpdate{ 0x11E8 };
		constexpr std::uint32_t m_x{ 0x11EC };
		constexpr std::uint32_t m_y{ 0x11F0 };
		constexpr std::uint32_t m_z{ 0x11F4 };
		constexpr std::uint32_t m_angle{ 0x11F8 };
		constexpr std::uint32_t m_errorHistory{ 0x11FC };
		constexpr std::uint32_t m_errorHistoryIndex{ 0x124C };
		constexpr std::uint32_t m_errorHistoryCount{ 0x1250 };
		constexpr std::uint32_t m_averageError{ 0x1254 };

	} // namespace c_fish

	namespace c_fogcontroller {

		constexpr std::uint32_t m_fog{ 0x608 };
		constexpr std::uint32_t m_bUseAngles{ 0x670 };
		constexpr std::uint32_t m_iChangedVariables{ 0x674 };

	} // namespace c_fogcontroller

	namespace c_fogplayerparams_t {

		constexpr std::uint32_t m_hCtrl{ 0x8 };
		constexpr std::uint32_t m_flTransitionTime{ 0xC };
		constexpr std::uint32_t m_OldColor{ 0x10 };
		constexpr std::uint32_t m_flOldStart{ 0x14 };
		constexpr std::uint32_t m_flOldEnd{ 0x18 };
		constexpr std::uint32_t m_flOldMaxDensity{ 0x1C };
		constexpr std::uint32_t m_flOldHDRColorScale{ 0x20 };
		constexpr std::uint32_t m_flOldFarZ{ 0x24 };
		constexpr std::uint32_t m_NewColor{ 0x28 };
		constexpr std::uint32_t m_flNewStart{ 0x2C };
		constexpr std::uint32_t m_flNewEnd{ 0x30 };
		constexpr std::uint32_t m_flNewMaxDensity{ 0x34 };
		constexpr std::uint32_t m_flNewHDRColorScale{ 0x38 };
		constexpr std::uint32_t m_flNewFarZ{ 0x3C };

	} // namespace c_fogplayerparams_t

	namespace c_footstepcontrol {

		constexpr std::uint32_t m_source{ 0xF58 };
		constexpr std::uint32_t m_destination{ 0xF60 };

	} // namespace c_footstepcontrol

	namespace c_funcconveyor {

		constexpr std::uint32_t m_vecMoveDirEntitySpace{ 0xE90 };
		constexpr std::uint32_t m_flTargetSpeed{ 0xE9C };
		constexpr std::uint32_t m_nTransitionStartTick{ 0xEA0 };
		constexpr std::uint32_t m_nTransitionDurationTicks{ 0xEA4 };
		constexpr std::uint32_t m_flTransitionStartSpeed{ 0xEA8 };
		constexpr std::uint32_t m_hConveyorModels{ 0xEB0 };
		constexpr std::uint32_t m_flCurrentConveyorOffset{ 0xEC8 };
		constexpr std::uint32_t m_flCurrentConveyorSpeed{ 0xECC };

	} // namespace c_funcconveyor

	namespace c_funcelectrifiedvolume {

		constexpr std::uint32_t m_nAmbientEffect{ 0xE88 };
		constexpr std::uint32_t m_EffectName{ 0xE90 };
		constexpr std::uint32_t m_bState{ 0xE98 };

	} // namespace c_funcelectrifiedvolume

	namespace c_funcladder {

		constexpr std::uint32_t m_vecLadderDir{ 0xE88 };
		constexpr std::uint32_t m_Dismounts{ 0xE98 };
		constexpr std::uint32_t m_vecLocalTop{ 0xEB0 };
		constexpr std::uint32_t m_vecPlayerMountPositionTop{ 0xEBC };
		constexpr std::uint32_t m_vecPlayerMountPositionBottom{ 0xEC8 };
		constexpr std::uint32_t m_flAutoRideSpeed{ 0xED4 };
		constexpr std::uint32_t m_bDisabled{ 0xED8 };
		constexpr std::uint32_t m_bFakeLadder{ 0xED9 };
		constexpr std::uint32_t m_bHasSlack{ 0xEDA };

	} // namespace c_funcladder

	namespace c_funcmonitor {

		constexpr std::uint32_t m_targetCamera{ 0xE88 };
		constexpr std::uint32_t m_nResolutionEnum{ 0xE90 };
		constexpr std::uint32_t m_bRenderShadows{ 0xE94 };
		constexpr std::uint32_t m_bUseUniqueColorTarget{ 0xE95 };
		constexpr std::uint32_t m_brushModelName{ 0xE98 };
		constexpr std::uint32_t m_hTargetCamera{ 0xEA0 };
		constexpr std::uint32_t m_bEnabled{ 0xEA4 };
		constexpr std::uint32_t m_bDraw3DSkybox{ 0xEA5 };

	} // namespace c_funcmonitor

	namespace c_functracktrain {

		constexpr std::uint32_t m_nLongAxis{ 0xE88 };
		constexpr std::uint32_t m_flRadius{ 0xE8C };
		constexpr std::uint32_t m_flLineLength{ 0xE90 };

	} // namespace c_functracktrain

	namespace c_gamerules {

		constexpr std::uint32_t __m_pChainEntity{ 0x8 };
		constexpr std::uint32_t m_nTotalPausedTicks{ 0x30 };
		constexpr std::uint32_t m_nPauseStartTick{ 0x34 };
		constexpr std::uint32_t m_bGamePaused{ 0x38 };

	} // namespace c_gamerules

	namespace c_globallight {

		constexpr std::uint32_t m_WindClothForceHandle{ 0xAD0 };

	} // namespace c_globallight

	namespace c_gradientfog {

		constexpr std::uint32_t m_hGradientFogTexture{ 0x608 };
		constexpr std::uint32_t m_flFogStartDistance{ 0x610 };
		constexpr std::uint32_t m_flFogEndDistance{ 0x614 };
		constexpr std::uint32_t m_bHeightFogEnabled{ 0x618 };
		constexpr std::uint32_t m_flFogStartHeight{ 0x61C };
		constexpr std::uint32_t m_flFogEndHeight{ 0x620 };
		constexpr std::uint32_t m_flFarZ{ 0x624 };
		constexpr std::uint32_t m_flFogMaxOpacity{ 0x628 };
		constexpr std::uint32_t m_flFogFalloffExponent{ 0x62C };
		constexpr std::uint32_t m_flFogVerticalExponent{ 0x630 };
		constexpr std::uint32_t m_fogColor{ 0x634 };
		constexpr std::uint32_t m_flFogStrength{ 0x638 };
		constexpr std::uint32_t m_flFadeTime{ 0x63C };
		constexpr std::uint32_t m_bStartDisabled{ 0x640 };
		constexpr std::uint32_t m_bIsEnabled{ 0x641 };
		constexpr std::uint32_t m_bGradientFogNeedsTextures{ 0x642 };

	} // namespace c_gradientfog

	namespace c_handletest {

		constexpr std::uint32_t m_Handle{ 0x608 };
		constexpr std::uint32_t m_bSendHandle{ 0x60C };

	} // namespace c_handletest

	namespace c_hostage {

		constexpr std::uint32_t m_entitySpottedState{ 0x13D8 };
		constexpr std::uint32_t m_leader{ 0x13F0 };
		constexpr std::uint32_t m_reuseTimer{ 0x13F8 };
		constexpr std::uint32_t m_vel{ 0x1410 };
		constexpr std::uint32_t m_isRescued{ 0x141C };
		constexpr std::uint32_t m_jumpedThisFrame{ 0x141D };
		constexpr std::uint32_t m_nHostageState{ 0x1420 };
		constexpr std::uint32_t m_bHandsHaveBeenCut{ 0x1424 };
		constexpr std::uint32_t m_hHostageGrabber{ 0x1428 };
		constexpr std::uint32_t m_fLastGrabTime{ 0x142C };
		constexpr std::uint32_t m_vecGrabbedPos{ 0x1430 };
		constexpr std::uint32_t m_flRescueStartTime{ 0x143C };
		constexpr std::uint32_t m_flGrabSuccessTime{ 0x1440 };
		constexpr std::uint32_t m_flDropStartTime{ 0x1444 };
		constexpr std::uint32_t m_flDeadOrRescuedTime{ 0x1448 };
		constexpr std::uint32_t m_blinkTimer{ 0x1450 };
		constexpr std::uint32_t m_lookAt{ 0x1468 };
		constexpr std::uint32_t m_lookAroundTimer{ 0x1478 };
		constexpr std::uint32_t m_isInit{ 0x1490 };
		constexpr std::uint32_t m_eyeAttachment{ 0x1491 };
		constexpr std::uint32_t m_chestAttachment{ 0x1492 };
		constexpr std::uint32_t m_pPredictionOwner{ 0x1498 };
		constexpr std::uint32_t m_fNewestAlphaThinkTime{ 0x14A0 };

	} // namespace c_hostage

	namespace c_inferno {

		constexpr std::uint32_t m_nfxFireDamageEffect{ 0xEC8 };
		constexpr std::uint32_t m_hInfernoPointsSnapshot{ 0xED0 };
		constexpr std::uint32_t m_hInfernoFillerPointsSnapshot{ 0xED8 };
		constexpr std::uint32_t m_hInfernoOutlinePointsSnapshot{ 0xEE0 };
		constexpr std::uint32_t m_hInfernoClimbingOutlinePointsSnapshot{ 0xEE8 };
		constexpr std::uint32_t m_hInfernoDecalsSnapshot{ 0xEF0 };
		constexpr std::uint32_t m_firePositions{ 0xEF8 };
		constexpr std::uint32_t m_fireParentPositions{ 0x11F8 };
		constexpr std::uint32_t m_bFireIsBurning{ 0x14F8 };
		constexpr std::uint32_t m_BurnNormal{ 0x1538 };
		constexpr std::uint32_t m_fireCount{ 0x1838 };
		constexpr std::uint32_t m_nInfernoType{ 0x183C };
		constexpr std::uint32_t m_nFireLifetime{ 0x1840 };
		constexpr std::uint32_t m_bInPostEffectTime{ 0x1844 };
		constexpr std::uint32_t m_lastFireCount{ 0x1848 };
		constexpr std::uint32_t m_nFireEffectTickBegin{ 0x184C };
		constexpr std::uint32_t m_drawableCount{ 0x8450 };
		constexpr std::uint32_t m_blosCheck{ 0x8454 };
		constexpr std::uint32_t m_nlosperiod{ 0x8458 };
		constexpr std::uint32_t m_maxFireHalfWidth{ 0x845C };
		constexpr std::uint32_t m_maxFireHeight{ 0x8460 };
		constexpr std::uint32_t m_minBounds{ 0x8464 };
		constexpr std::uint32_t m_maxBounds{ 0x8470 };
		constexpr std::uint32_t m_flLastGrassBurnThink{ 0x847C };

	} // namespace c_inferno

	namespace c_infovisibilitybox {

		constexpr std::uint32_t m_nMode{ 0x60C };
		constexpr std::uint32_t m_vBoxSize{ 0x610 };
		constexpr std::uint32_t m_bEnabled{ 0x61C };

	} // namespace c_infovisibilitybox

	namespace c_ironsightcontroller {

		constexpr std::uint32_t m_bIronSightAvailable{ 0x10 };
		constexpr std::uint32_t m_flIronSightAmount{ 0x14 };
		constexpr std::uint32_t m_flIronSightAmountGained{ 0x18 };
		constexpr std::uint32_t m_flIronSightAmountBiased{ 0x1C };
		constexpr std::uint32_t m_flIronSightAmount_Interpolated{ 0x20 };
		constexpr std::uint32_t m_flIronSightAmountGained_Interpolated{ 0x24 };
		constexpr std::uint32_t m_flIronSightAmountBiased_Interpolated{ 0x28 };
		constexpr std::uint32_t m_flInterpolationLastUpdated{ 0x2C };
		constexpr std::uint32_t m_angDeltaAverage{ 0x30 };
		constexpr std::uint32_t m_angViewLast{ 0x90 };
		constexpr std::uint32_t m_vecDotCoords{ 0x9C };
		constexpr std::uint32_t m_flFiringInaccuracyExtraWidthMultiplier{ 0xA4 };
		constexpr std::uint32_t m_flSpeedRatio{ 0xA8 };

	} // namespace c_ironsightcontroller

	namespace c_item {

		constexpr std::uint32_t m_pReticleHintTextName{ 0x18C0 };

	} // namespace c_item

	namespace c_itemdogtags {

		constexpr std::uint32_t m_OwningPlayer{ 0x19C0 };
		constexpr std::uint32_t m_KillingPlayer{ 0x19C4 };

	} // namespace c_itemdogtags

	namespace c_keychainmodule {

		constexpr std::uint32_t m_nKeychainDefID{ 0x1170 };
		constexpr std::uint32_t m_nKeychainSeed{ 0x1174 };

	} // namespace c_keychainmodule

	namespace c_knife {

		constexpr std::uint32_t m_bFirstAttack{ 0x1F40 };

	} // namespace c_knife

	namespace c_lightentity {

		constexpr std::uint32_t m_CLightComponent{ 0xE88 };

	} // namespace c_lightentity

	namespace c_localtempentity {

		constexpr std::uint32_t flags{ 0x1168 };
		constexpr std::uint32_t die{ 0x116C };
		constexpr std::uint32_t m_flFrameMax{ 0x1170 };
		constexpr std::uint32_t x{ 0x1174 };
		constexpr std::uint32_t y{ 0x1178 };
		constexpr std::uint32_t fadeSpeed{ 0x117C };
		constexpr std::uint32_t bounceFactor{ 0x1180 };
		constexpr std::uint32_t hitSound{ 0x1184 };
		constexpr std::uint32_t priority{ 0x1188 };
		constexpr std::uint32_t tentOffset{ 0x118C };
		constexpr std::uint32_t m_vecTempEntAngVelocity{ 0x1198 };
		constexpr std::uint32_t tempent_renderamt{ 0x11A4 };
		constexpr std::uint32_t m_vecNormal{ 0x11A8 };
		constexpr std::uint32_t m_flSpriteScale{ 0x11B4 };
		constexpr std::uint32_t m_nFlickerFrame{ 0x11B8 };
		constexpr std::uint32_t m_flFrameRate{ 0x11BC };
		constexpr std::uint32_t m_flFrame{ 0x11C0 };
		constexpr std::uint32_t m_pszImpactEffect{ 0x11C8 };
		constexpr std::uint32_t m_pszParticleEffect{ 0x11D0 };
		constexpr std::uint32_t m_bParticleCollision{ 0x11D8 };
		constexpr std::uint32_t m_iLastCollisionFrame{ 0x11DC };
		constexpr std::uint32_t m_vLastCollisionOrigin{ 0x11E0 };
		constexpr std::uint32_t m_vecTempEntVelocity{ 0x11EC };
		constexpr std::uint32_t m_vecPrevAbsOrigin{ 0x11F8 };
		constexpr std::uint32_t m_vecTempEntAcceleration{ 0x1204 };

	} // namespace c_localtempentity

	namespace c_mapvetopickcontroller {

		constexpr std::uint32_t m_nDraftType{ 0x618 };
		constexpr std::uint32_t m_nTeamWinningCoinToss{ 0x61C };
		constexpr std::uint32_t m_nTeamWithFirstChoice{ 0x620 };
		constexpr std::uint32_t m_nVoteMapIdsList{ 0x720 };
		constexpr std::uint32_t m_nAccountIDs{ 0x73C };
		constexpr std::uint32_t m_nMapId0{ 0x83C };
		constexpr std::uint32_t m_nMapId1{ 0x93C };
		constexpr std::uint32_t m_nMapId2{ 0xA3C };
		constexpr std::uint32_t m_nMapId3{ 0xB3C };
		constexpr std::uint32_t m_nMapId4{ 0xC3C };
		constexpr std::uint32_t m_nMapId5{ 0xD3C };
		constexpr std::uint32_t m_nStartingSide0{ 0xE3C };
		constexpr std::uint32_t m_nCurrentPhase{ 0xF3C };
		constexpr std::uint32_t m_nPhaseStartTick{ 0xF40 };
		constexpr std::uint32_t m_nPhaseDurationTicks{ 0xF44 };
		constexpr std::uint32_t m_nPostDataUpdateTick{ 0xF48 };
		constexpr std::uint32_t m_bDisabledHud{ 0xF4C };

	} // namespace c_mapvetopickcontroller

	namespace c_molotovprojectile {

		constexpr std::uint32_t m_bIsIncGrenade{ 0x1438 };

	} // namespace c_molotovprojectile

	namespace c_multimeter {

		constexpr std::uint32_t m_hTargetC4{ 0x1170 };

	} // namespace c_multimeter

	namespace c_nametagmodule {

		constexpr std::uint32_t m_strNametagString{ 0x1170 };

	} // namespace c_nametagmodule

	namespace c_omnilight {

		constexpr std::uint32_t m_flInnerAngle{ 0x1198 };
		constexpr std::uint32_t m_flOuterAngle{ 0x119C };
		constexpr std::uint32_t m_bShowLight{ 0x11A0 };

	} // namespace c_omnilight

	namespace c_particlesystem {

		constexpr std::uint32_t m_szSnapshotFileName{ 0xE88 };
		constexpr std::uint32_t m_bActive{ 0x1088 };
		constexpr std::uint32_t m_bFrozen{ 0x1089 };
		constexpr std::uint32_t m_flFreezeTransitionDuration{ 0x108C };
		constexpr std::uint32_t m_nStopType{ 0x1090 };
		constexpr std::uint32_t m_bAnimateDuringGameplayPause{ 0x1094 };
		constexpr std::uint32_t m_iEffectIndex{ 0x1098 };
		constexpr std::uint32_t m_flStartTime{ 0x10A0 };
		constexpr std::uint32_t m_flPreSimTime{ 0x10A4 };
		constexpr std::uint32_t m_vServerControlPoints{ 0x10A8 };
		constexpr std::uint32_t m_iServerControlPointAssignments{ 0x10D8 };
		constexpr std::uint32_t m_hControlPointEnts{ 0x10DC };
		constexpr std::uint32_t m_bNoSave{ 0x11DC };
		constexpr std::uint32_t m_bNoFreeze{ 0x11DD };
		constexpr std::uint32_t m_bNoRamp{ 0x11DE };
		constexpr std::uint32_t m_bStartActive{ 0x11DF };
		constexpr std::uint32_t m_iszEffectName{ 0x11E0 };
		constexpr std::uint32_t m_iszControlPointNames{ 0x11E8 };
		constexpr std::uint32_t m_nDataCP{ 0x13E8 };
		constexpr std::uint32_t m_vecDataCPValue{ 0x13EC };
		constexpr std::uint32_t m_nTintCP{ 0x13F8 };
		constexpr std::uint32_t m_clrTint{ 0x13FC };
		constexpr std::uint32_t m_bOldActive{ 0x1420 };
		constexpr std::uint32_t m_bOldFrozen{ 0x1421 };

	} // namespace c_particlesystem

	namespace c_pathparticlerope {

		constexpr std::uint32_t m_bStartActive{ 0x610 };
		constexpr std::uint32_t m_flMaxSimulationTime{ 0x614 };
		constexpr std::uint32_t m_iszEffectName{ 0x618 };
		constexpr std::uint32_t m_PathNodes_Name{ 0x620 };
		constexpr std::uint32_t m_flParticleSpacing{ 0x638 };
		constexpr std::uint32_t m_flSlack{ 0x63C };
		constexpr std::uint32_t m_flRadius{ 0x640 };
		constexpr std::uint32_t m_ColorTint{ 0x644 };
		constexpr std::uint32_t m_nEffectState{ 0x648 };
		constexpr std::uint32_t m_iEffectIndex{ 0x650 };
		constexpr std::uint32_t m_PathNodes_Position{ 0x658 };
		constexpr std::uint32_t m_PathNodes_TangentIn{ 0x670 };
		constexpr std::uint32_t m_PathNodes_TangentOut{ 0x688 };
		constexpr std::uint32_t m_PathNodes_Color{ 0x6A0 };
		constexpr std::uint32_t m_PathNodes_PinEnabled{ 0x6B8 };
		constexpr std::uint32_t m_PathNodes_RadiusScale{ 0x6D0 };

	} // namespace c_pathparticlerope

	namespace c_physicsprop {

		constexpr std::uint32_t m_bAwake{ 0x12D0 };

	} // namespace c_physicsprop

	namespace c_physmagnet {

		constexpr std::uint32_t m_aAttachedObjectsFromServer{ 0x1168 };
		constexpr std::uint32_t m_aAttachedObjects{ 0x1180 };

	} // namespace c_physmagnet

	namespace c_physpropclientside {

		constexpr std::uint32_t m_flTouchDelta{ 0x12D0 };
		constexpr std::uint32_t m_fDeathTime{ 0x12D4 };
		constexpr std::uint32_t m_vecDamagePosition{ 0x12D8 };
		constexpr std::uint32_t m_vecDamageDirection{ 0x12E4 };
		constexpr std::uint32_t m_nDamageType{ 0x12F0 };

	} // namespace c_physpropclientside

	namespace c_plantedc4 {

		constexpr std::uint32_t m_bBombTicking{ 0x1170 };
		constexpr std::uint32_t m_nBombSite{ 0x1174 };
		constexpr std::uint32_t m_nSourceSoundscapeHash{ 0x1178 };
		constexpr std::uint32_t m_entitySpottedState{ 0x1180 };
		constexpr std::uint32_t m_flNextGlow{ 0x1198 };
		constexpr std::uint32_t m_flNextBeep{ 0x119C };
		constexpr std::uint32_t m_flC4Blow{ 0x11A0 };
		constexpr std::uint32_t m_bCannotBeDefused{ 0x11A4 };
		constexpr std::uint32_t m_bHasExploded{ 0x11A5 };
		constexpr std::uint32_t m_flTimerLength{ 0x11A8 };
		constexpr std::uint32_t m_bBeingDefused{ 0x11AC };
		constexpr std::uint32_t m_bTriggerWarning{ 0x11B0 };
		constexpr std::uint32_t m_bExplodeWarning{ 0x11B4 };
		constexpr std::uint32_t m_bC4Activated{ 0x11B8 };
		constexpr std::uint32_t m_bTenSecWarning{ 0x11B9 };
		constexpr std::uint32_t m_flDefuseLength{ 0x11BC };
		constexpr std::uint32_t m_flDefuseCountDown{ 0x11C0 };
		constexpr std::uint32_t m_bBombDefused{ 0x11C4 };
		constexpr std::uint32_t m_hBombDefuser{ 0x11C8 };
		constexpr std::uint32_t m_AttributeManager{ 0x11D0 };
		constexpr std::uint32_t m_hDefuserMultimeter{ 0x16A0 };
		constexpr std::uint32_t m_flNextRadarFlashTime{ 0x16A4 };
		constexpr std::uint32_t m_bRadarFlash{ 0x16A8 };
		constexpr std::uint32_t m_pBombDefuser{ 0x16AC };
		constexpr std::uint32_t m_fLastDefuseTime{ 0x16B0 };
		constexpr std::uint32_t m_pPredictionOwner{ 0x16B8 };
		constexpr std::uint32_t m_vecC4ExplodeSpectatePos{ 0x16C0 };
		constexpr std::uint32_t m_vecC4ExplodeSpectateAng{ 0x16CC };
		constexpr std::uint32_t m_flC4ExplodeSpectateDuration{ 0x16D8 };

	} // namespace c_plantedc4

	namespace c_playerping {

		constexpr std::uint32_t m_hPlayer{ 0x638 };
		constexpr std::uint32_t m_hPingedEntity{ 0x63C };
		constexpr std::uint32_t m_iType{ 0x640 };
		constexpr std::uint32_t m_bUrgent{ 0x644 };
		constexpr std::uint32_t m_szPlaceName{ 0x645 };

	} // namespace c_playerping

	namespace c_playerspraydecal {

		constexpr std::uint32_t m_nUniqueID{ 0xE88 };
		constexpr std::uint32_t m_unAccountID{ 0xE8C };
		constexpr std::uint32_t m_unTraceID{ 0xE90 };
		constexpr std::uint32_t m_rtGcTime{ 0xE94 };
		constexpr std::uint32_t m_vecEndPos{ 0xE98 };
		constexpr std::uint32_t m_vecStart{ 0xEA4 };
		constexpr std::uint32_t m_vecLeft{ 0xEB0 };
		constexpr std::uint32_t m_vecNormal{ 0xEBC };
		constexpr std::uint32_t m_nPlayer{ 0xEC8 };
		constexpr std::uint32_t m_nEntity{ 0xECC };
		constexpr std::uint32_t m_nHitbox{ 0xED0 };
		constexpr std::uint32_t m_flCreationTime{ 0xED4 };
		constexpr std::uint32_t m_nTintID{ 0xED8 };
		constexpr std::uint32_t m_nVersion{ 0xEDC };
		constexpr std::uint32_t m_ubSignature{ 0xEDD };
		constexpr std::uint32_t m_SprayRenderHelper{ 0xF68 };

	} // namespace c_playerspraydecal

	namespace c_playervisibility {

		constexpr std::uint32_t m_flVisibilityStrength{ 0x608 };
		constexpr std::uint32_t m_flFogDistanceMultiplier{ 0x60C };
		constexpr std::uint32_t m_flFogMaxDensityMultiplier{ 0x610 };
		constexpr std::uint32_t m_flFadeTime{ 0x614 };
		constexpr std::uint32_t m_bStartDisabled{ 0x618 };
		constexpr std::uint32_t m_bIsEnabled{ 0x619 };

	} // namespace c_playervisibility

	namespace c_pointcamera {

		constexpr std::uint32_t m_FOV{ 0x608 };
		constexpr std::uint32_t m_Resolution{ 0x60C };
		constexpr std::uint32_t m_bFogEnable{ 0x610 };
		constexpr std::uint32_t m_FogColor{ 0x611 };
		constexpr std::uint32_t m_flFogStart{ 0x618 };
		constexpr std::uint32_t m_flFogEnd{ 0x61C };
		constexpr std::uint32_t m_flFogMaxDensity{ 0x620 };
		constexpr std::uint32_t m_bActive{ 0x624 };
		constexpr std::uint32_t m_bUseScreenAspectRatio{ 0x625 };
		constexpr std::uint32_t m_flAspectRatio{ 0x628 };
		constexpr std::uint32_t m_bNoSky{ 0x62C };
		constexpr std::uint32_t m_fBrightness{ 0x630 };
		constexpr std::uint32_t m_flZFar{ 0x634 };
		constexpr std::uint32_t m_flZNear{ 0x638 };
		constexpr std::uint32_t m_bCanHLTVUse{ 0x63C };
		constexpr std::uint32_t m_bAlignWithParent{ 0x63D };
		constexpr std::uint32_t m_bDofEnabled{ 0x63E };
		constexpr std::uint32_t m_flDofNearBlurry{ 0x640 };
		constexpr std::uint32_t m_flDofNearCrisp{ 0x644 };
		constexpr std::uint32_t m_flDofFarCrisp{ 0x648 };
		constexpr std::uint32_t m_flDofFarBlurry{ 0x64C };
		constexpr std::uint32_t m_flDofTiltToGround{ 0x650 };
		constexpr std::uint32_t m_TargetFOV{ 0x654 };
		constexpr std::uint32_t m_DegreesPerSecond{ 0x658 };
		constexpr std::uint32_t m_bIsOn{ 0x65C };
		constexpr std::uint32_t m_pNext{ 0x660 };

	} // namespace c_pointcamera

	namespace c_pointcameravfov {

		constexpr std::uint32_t m_flVerticalFOV{ 0x668 };

	} // namespace c_pointcameravfov

	namespace c_pointclientuidialog {

		constexpr std::uint32_t m_hActivator{ 0xEB8 };
		constexpr std::uint32_t m_bStartEnabled{ 0xEBC };

	} // namespace c_pointclientuidialog

	namespace c_pointclientuihud {

		constexpr std::uint32_t m_bCheckCSSClasses{ 0xEC0 };
		constexpr std::uint32_t m_bIgnoreInput{ 0x1038 };
		constexpr std::uint32_t m_flWidth{ 0x103C };
		constexpr std::uint32_t m_flHeight{ 0x1040 };
		constexpr std::uint32_t m_flDPI{ 0x1044 };
		constexpr std::uint32_t m_flInteractDistance{ 0x1048 };
		constexpr std::uint32_t m_flDepthOffset{ 0x104C };
		constexpr std::uint32_t m_unOwnerContext{ 0x1050 };
		constexpr std::uint32_t m_unHorizontalAlign{ 0x1054 };
		constexpr std::uint32_t m_unVerticalAlign{ 0x1058 };
		constexpr std::uint32_t m_unOrientation{ 0x105C };
		constexpr std::uint32_t m_bAllowInteractionFromAllSceneWorlds{ 0x1060 };
		constexpr std::uint32_t m_vecCSSClasses{ 0x1068 };

	} // namespace c_pointclientuihud

	namespace c_pointclientuiworldpanel {

		constexpr std::uint32_t m_bForceRecreateNextUpdate{ 0xEC0 };
		constexpr std::uint32_t m_bMoveViewToPlayerNextThink{ 0xEC1 };
		constexpr std::uint32_t m_bCheckCSSClasses{ 0xEC2 };
		constexpr std::uint32_t m_anchorDeltaTransform{ 0xED0 };
		constexpr std::uint32_t m_pOffScreenIndicator{ 0x1060 };
		constexpr std::uint32_t m_bIgnoreInput{ 0x1088 };
		constexpr std::uint32_t m_bLit{ 0x1089 };
		constexpr std::uint32_t m_bFollowPlayerAcrossTeleport{ 0x108A };
		constexpr std::uint32_t m_flWidth{ 0x108C };
		constexpr std::uint32_t m_flHeight{ 0x1090 };
		constexpr std::uint32_t m_flDPI{ 0x1094 };
		constexpr std::uint32_t m_flInteractDistance{ 0x1098 };
		constexpr std::uint32_t m_flDepthOffset{ 0x109C };
		constexpr std::uint32_t m_unOwnerContext{ 0x10A0 };
		constexpr std::uint32_t m_unHorizontalAlign{ 0x10A4 };
		constexpr std::uint32_t m_unVerticalAlign{ 0x10A8 };
		constexpr std::uint32_t m_unOrientation{ 0x10AC };
		constexpr std::uint32_t m_bAllowInteractionFromAllSceneWorlds{ 0x10B0 };
		constexpr std::uint32_t m_vecCSSClasses{ 0x10B8 };
		constexpr std::uint32_t m_bOpaque{ 0x10D0 };
		constexpr std::uint32_t m_bNoDepth{ 0x10D1 };
		constexpr std::uint32_t m_bVisibleWhenParentNoDraw{ 0x10D2 };
		constexpr std::uint32_t m_bRenderBackface{ 0x10D3 };
		constexpr std::uint32_t m_bUseOffScreenIndicator{ 0x10D4 };
		constexpr std::uint32_t m_bExcludeFromSaveGames{ 0x10D5 };
		constexpr std::uint32_t m_bGrabbable{ 0x10D6 };
		constexpr std::uint32_t m_bOnlyRenderToTexture{ 0x10D7 };
		constexpr std::uint32_t m_bDisableMipGen{ 0x10D8 };
		constexpr std::uint32_t m_nExplicitImageLayout{ 0x10DC };

	} // namespace c_pointclientuiworldpanel

	namespace c_pointclientuiworldtextpanel {

		constexpr std::uint32_t m_messageText{ 0x10E0 };

	} // namespace c_pointclientuiworldtextpanel

	namespace c_pointcommentarynode {

		constexpr std::uint32_t m_bActive{ 0x1180 };
		constexpr std::uint32_t m_bWasActive{ 0x1181 };
		constexpr std::uint32_t m_flEndTime{ 0x1184 };
		constexpr std::uint32_t m_flStartTime{ 0x1188 };
		constexpr std::uint32_t m_flStartTimeInCommentary{ 0x118C };
		constexpr std::uint32_t m_iszCommentaryFile{ 0x1190 };
		constexpr std::uint32_t m_iszTitle{ 0x1198 };
		constexpr std::uint32_t m_iszSpeakers{ 0x11A0 };
		constexpr std::uint32_t m_iNodeNumber{ 0x11A8 };
		constexpr std::uint32_t m_iNodeNumberMax{ 0x11AC };
		constexpr std::uint32_t m_bListenedTo{ 0x11B0 };
		constexpr std::uint32_t m_sndCommentary{ 0x11B8 };
		constexpr std::uint32_t m_hViewPosition{ 0x11C0 };
		constexpr std::uint32_t m_bRestartAfterRestore{ 0x11C4 };

	} // namespace c_pointcommentarynode

	namespace c_pointvalueremapper {

		constexpr std::uint32_t m_bDisabled{ 0x608 };
		constexpr std::uint32_t m_bDisabledOld{ 0x609 };
		constexpr std::uint32_t m_bUpdateOnClient{ 0x60A };
		constexpr std::uint32_t m_nInputType{ 0x60C };
		constexpr std::uint32_t m_hRemapLineStart{ 0x610 };
		constexpr std::uint32_t m_hRemapLineEnd{ 0x614 };
		constexpr std::uint32_t m_flMaximumChangePerSecond{ 0x618 };
		constexpr std::uint32_t m_flDisengageDistance{ 0x61C };
		constexpr std::uint32_t m_flEngageDistance{ 0x620 };
		constexpr std::uint32_t m_bRequiresUseKey{ 0x624 };
		constexpr std::uint32_t m_nOutputType{ 0x628 };
		constexpr std::uint32_t m_hOutputEntities{ 0x630 };
		constexpr std::uint32_t m_nHapticsType{ 0x648 };
		constexpr std::uint32_t m_nMomentumType{ 0x64C };
		constexpr std::uint32_t m_flMomentumModifier{ 0x650 };
		constexpr std::uint32_t m_flSnapValue{ 0x654 };
		constexpr std::uint32_t m_flCurrentMomentum{ 0x658 };
		constexpr std::uint32_t m_nRatchetType{ 0x65C };
		constexpr std::uint32_t m_flRatchetOffset{ 0x660 };
		constexpr std::uint32_t m_flInputOffset{ 0x664 };
		constexpr std::uint32_t m_bEngaged{ 0x668 };
		constexpr std::uint32_t m_bFirstUpdate{ 0x669 };
		constexpr std::uint32_t m_flPreviousValue{ 0x66C };
		constexpr std::uint32_t m_flPreviousUpdateTickTime{ 0x670 };
		constexpr std::uint32_t m_vecPreviousTestPoint{ 0x674 };

	} // namespace c_pointvalueremapper

	namespace c_pointworldtext {

		constexpr std::uint32_t m_bForceRecreateNextUpdate{ 0xE90 };
		constexpr std::uint32_t m_nTextWidthPx{ 0xEA8 };
		constexpr std::uint32_t m_nTextHeightPx{ 0xEAC };
		constexpr std::uint32_t m_messageText{ 0xEB0 };
		constexpr std::uint32_t m_FontName{ 0x10B0 };
		constexpr std::uint32_t m_BackgroundMaterialName{ 0x10F0 };
		constexpr std::uint32_t m_bEnabled{ 0x1130 };
		constexpr std::uint32_t m_bFullbright{ 0x1131 };
		constexpr std::uint32_t m_flWorldUnitsPerPx{ 0x1134 };
		constexpr std::uint32_t m_flFontSize{ 0x1138 };
		constexpr std::uint32_t m_flDepthOffset{ 0x113C };
		constexpr std::uint32_t m_bDrawBackground{ 0x1140 };
		constexpr std::uint32_t m_flBackgroundBorderWidth{ 0x1144 };
		constexpr std::uint32_t m_flBackgroundBorderHeight{ 0x1148 };
		constexpr std::uint32_t m_flBackgroundWorldToUV{ 0x114C };
		constexpr std::uint32_t m_Color{ 0x1150 };
		constexpr std::uint32_t m_nJustifyHorizontal{ 0x1154 };
		constexpr std::uint32_t m_nJustifyVertical{ 0x1158 };
		constexpr std::uint32_t m_nReorientMode{ 0x115C };

	} // namespace c_pointworldtext

	namespace c_postprocessingvolume {

		constexpr std::uint32_t m_hPostSettings{ 0xF68 };
		constexpr std::uint32_t m_flFadeDuration{ 0xF70 };
		constexpr std::uint32_t m_flMinLogExposure{ 0xF74 };
		constexpr std::uint32_t m_flMaxLogExposure{ 0xF78 };
		constexpr std::uint32_t m_flMinExposure{ 0xF7C };
		constexpr std::uint32_t m_flMaxExposure{ 0xF80 };
		constexpr std::uint32_t m_flExposureCompensation{ 0xF84 };
		constexpr std::uint32_t m_flExposureFadeSpeedUp{ 0xF88 };
		constexpr std::uint32_t m_flExposureFadeSpeedDown{ 0xF8C };
		constexpr std::uint32_t m_flTonemapEVSmoothingRange{ 0xF90 };
		constexpr std::uint32_t m_bMaster{ 0xF94 };
		constexpr std::uint32_t m_bExposureControl{ 0xF95 };

	} // namespace c_postprocessingvolume

	namespace c_precipitation {

		constexpr std::uint32_t m_flDensity{ 0xF58 };
		constexpr std::uint32_t m_flParticleInnerDist{ 0xF68 };
		constexpr std::uint32_t m_pParticleDef{ 0xF70 };
		constexpr std::uint32_t m_tParticlePrecipTraceTimer{ 0xF98 };
		constexpr std::uint32_t m_bActiveParticlePrecipEmitter{ 0xFA0 };
		constexpr std::uint32_t m_bParticlePrecipInitialized{ 0xFA1 };
		constexpr std::uint32_t m_bHasSimulatedSinceLastSceneObjectUpdate{ 0xFA2 };
		constexpr std::uint32_t m_nAvailableSheetSequencesMaxIndex{ 0xFA4 };

	} // namespace c_precipitation

	namespace c_ragdollprop {

		constexpr std::uint32_t m_ragEnabled{ 0x1170 };
		constexpr std::uint32_t m_ragPos{ 0x1188 };
		constexpr std::uint32_t m_ragAngles{ 0x11A0 };
		constexpr std::uint32_t m_flBlendWeight{ 0x11B8 };
		constexpr std::uint32_t m_hRagdollSource{ 0x11BC };
		constexpr std::uint32_t m_iEyeAttachment{ 0x11C0 };
		constexpr std::uint32_t m_flBlendWeightCurrent{ 0x11C4 };
		constexpr std::uint32_t m_parentPhysicsBoneIndices{ 0x11C8 };
		constexpr std::uint32_t m_worldSpaceBoneComputationOrder{ 0x11E0 };

	} // namespace c_ragdollprop

	namespace c_ragdollpropattached {

		constexpr std::uint32_t m_boneIndexAttached{ 0x11F8 };
		constexpr std::uint32_t m_ragdollAttachedObjectIndex{ 0x11FC };
		constexpr std::uint32_t m_attachmentPointBoneSpace{ 0x1200 };
		constexpr std::uint32_t m_attachmentPointRagdollSpace{ 0x120C };
		constexpr std::uint32_t m_vecOffset{ 0x1218 };
		constexpr std::uint32_t m_parentTime{ 0x1224 };
		constexpr std::uint32_t m_bHasParent{ 0x1228 };

	} // namespace c_ragdollpropattached

	namespace c_rectlight {

		constexpr std::uint32_t m_bShowLight{ 0x1198 };

	} // namespace c_rectlight

	namespace c_retakegamerules {

		constexpr std::uint32_t m_nMatchSeed{ 0x138 };
		constexpr std::uint32_t m_bBlockersPresent{ 0x13C };
		constexpr std::uint32_t m_bRoundInProgress{ 0x13D };
		constexpr std::uint32_t m_iFirstSecondHalfRound{ 0x140 };
		constexpr std::uint32_t m_iBombSite{ 0x144 };
		constexpr std::uint32_t m_hBombPlanter{ 0x148 };

	} // namespace c_retakegamerules

	namespace c_ropekeyframe {

		constexpr std::uint32_t m_bEndPointAttachmentAnglesDirty{ 0x0 };
		constexpr std::uint32_t m_bEndPointAttachmentPositionsDirty{ 0x0 };
		constexpr std::uint32_t m_bNewDataThisFrame{ 0x0 };
		constexpr std::uint32_t m_bPhysicsInitted{ 0x0 };
		constexpr std::uint32_t m_LinksTouchingSomething{ 0xE90 };
		constexpr std::uint32_t m_nLinksTouchingSomething{ 0xE94 };
		constexpr std::uint32_t m_bApplyWind{ 0xE98 };
		constexpr std::uint32_t m_fPrevLockedPoints{ 0xE9C };
		constexpr std::uint32_t m_iForcePointMoveCounter{ 0xEA0 };
		constexpr std::uint32_t m_bPrevEndPointPos{ 0xEA4 };
		constexpr std::uint32_t m_vPrevEndPointPos{ 0xEA8 };
		constexpr std::uint32_t m_flCurScroll{ 0xEC0 };
		constexpr std::uint32_t m_flScrollSpeed{ 0xEC4 };
		constexpr std::uint32_t m_RopeFlags{ 0xEC8 };
		constexpr std::uint32_t m_iRopeMaterialModelIndex{ 0xED0 };
		constexpr std::uint32_t m_nSegments{ 0x1148 };
		constexpr std::uint32_t m_hStartPoint{ 0x114C };
		constexpr std::uint32_t m_hEndPoint{ 0x1150 };
		constexpr std::uint32_t m_iStartAttachment{ 0x1154 };
		constexpr std::uint32_t m_iEndAttachment{ 0x1155 };
		constexpr std::uint32_t m_Subdiv{ 0x1156 };
		constexpr std::uint32_t m_RopeLength{ 0x1158 };
		constexpr std::uint32_t m_Slack{ 0x115A };
		constexpr std::uint32_t m_TextureScale{ 0x115C };
		constexpr std::uint32_t m_fLockedPoints{ 0x1160 };
		constexpr std::uint32_t m_nChangeCount{ 0x1161 };
		constexpr std::uint32_t m_Width{ 0x1164 };
		constexpr std::uint32_t m_PhysicsDelegate{ 0x1168 };
		constexpr std::uint32_t m_hMaterial{ 0x1178 };
		constexpr std::uint32_t m_TextureHeight{ 0x1180 };
		constexpr std::uint32_t m_vecImpulse{ 0x1184 };
		constexpr std::uint32_t m_vecPreviousImpulse{ 0x1190 };
		constexpr std::uint32_t m_flCurrentGustTimer{ 0x119C };
		constexpr std::uint32_t m_flCurrentGustLifetime{ 0x11A0 };
		constexpr std::uint32_t m_flTimeToNextGust{ 0x11A4 };
		constexpr std::uint32_t m_vWindDir{ 0x11A8 };
		constexpr std::uint32_t m_vColorMod{ 0x11B4 };
		constexpr std::uint32_t m_vCachedEndPointAttachmentPos{ 0x11C0 };
		constexpr std::uint32_t m_vCachedEndPointAttachmentAngle{ 0x11D8 };
		constexpr std::uint32_t m_bConstrainBetweenEndpoints{ 0x11F0 };

	} // namespace c_ropekeyframe

	namespace c_ropekeyframe__cphysicsdelegate {

		constexpr std::uint32_t m_pKeyframe{ 0x8 };

	} // namespace c_ropekeyframe__cphysicsdelegate

	namespace c_sceneentity {

		constexpr std::uint32_t m_bIsPlayingBack{ 0x610 };
		constexpr std::uint32_t m_bPaused{ 0x611 };
		constexpr std::uint32_t m_bMultiplayer{ 0x612 };
		constexpr std::uint32_t m_bAutogenerated{ 0x613 };
		constexpr std::uint32_t m_flForceClientTime{ 0x614 };
		constexpr std::uint32_t m_nSceneStringIndex{ 0x618 };
		constexpr std::uint32_t m_bClientOnly{ 0x61A };
		constexpr std::uint32_t m_hOwner{ 0x61C };
		constexpr std::uint32_t m_hActorList{ 0x620 };
		constexpr std::uint32_t m_bWasPlaying{ 0x638 };
		constexpr std::uint32_t m_QueuedEvents{ 0x648 };
		constexpr std::uint32_t m_flCurrentTime{ 0x660 };

	} // namespace c_sceneentity

	namespace c_sceneentity__queuedevents_t {

		constexpr std::uint32_t starttime{ 0x0 };

	} // namespace c_sceneentity__queuedevents_t

	namespace c_shatterglassshardphysics {

		constexpr std::uint32_t m_ShardDesc{ 0x12E8 };

	} // namespace c_shatterglassshardphysics

	namespace c_skycamera {

		constexpr std::uint32_t m_skyboxData{ 0x608 };
		constexpr std::uint32_t m_skyboxSlotToken{ 0x698 };
		constexpr std::uint32_t m_bUseAngles{ 0x69C };
		constexpr std::uint32_t m_pNext{ 0x6A0 };

	} // namespace c_skycamera

	namespace c_smokegrenadeprojectile {

		constexpr std::uint32_t m_nSmokeEffectTickBegin{ 0x1450 };
		constexpr std::uint32_t m_bDidSmokeEffect{ 0x1454 };
		constexpr std::uint32_t m_nRandomSeed{ 0x1458 };
		constexpr std::uint32_t m_vSmokeColor{ 0x145C };
		constexpr std::uint32_t m_vSmokeDetonationPos{ 0x1468 };
		constexpr std::uint32_t m_VoxelFrameData{ 0x1478 };
		constexpr std::uint32_t m_nVoxelFrameDataSize{ 0x1490 };
		constexpr std::uint32_t m_nVoxelUpdate{ 0x1494 };
		constexpr std::uint32_t m_bSmokeVolumeDataReceived{ 0x1498 };
		constexpr std::uint32_t m_bSmokeEffectSpawned{ 0x1499 };

	} // namespace c_smokegrenadeprojectile

	namespace c_soundareaentitybase {

		constexpr std::uint32_t m_bDisabled{ 0x608 };
		constexpr std::uint32_t m_bWasEnabled{ 0x610 };
		constexpr std::uint32_t m_iszSoundAreaType{ 0x618 };
		constexpr std::uint32_t m_vPos{ 0x620 };

	} // namespace c_soundareaentitybase

	namespace c_soundareaentityorientedbox {

		constexpr std::uint32_t m_vMin{ 0x630 };
		constexpr std::uint32_t m_vMax{ 0x63C };

	} // namespace c_soundareaentityorientedbox

	namespace c_soundareaentitysphere {

		constexpr std::uint32_t m_flRadius{ 0x630 };

	} // namespace c_soundareaentitysphere

	namespace c_soundeventaabbentity {

		constexpr std::uint32_t m_vMins{ 0x6B8 };
		constexpr std::uint32_t m_vMaxs{ 0x6C4 };

	} // namespace c_soundeventaabbentity

	namespace c_soundeventconeentity {

		constexpr std::uint32_t m_flEmitterAngle{ 0x6B8 };
		constexpr std::uint32_t m_flSweetSpotAngle{ 0x6BC };
		constexpr std::uint32_t m_flAttenMin{ 0x6C0 };
		constexpr std::uint32_t m_flAttenMax{ 0x6C4 };
		constexpr std::uint32_t m_iszParameterName{ 0x6C8 };

	} // namespace c_soundeventconeentity

	namespace c_soundevententity {

		constexpr std::uint32_t m_bClientSideOnly{ 0x0 };
		constexpr std::uint32_t m_bStartOnSpawn{ 0x608 };
		constexpr std::uint32_t m_bToLocalPlayer{ 0x609 };
		constexpr std::uint32_t m_bStopOnNew{ 0x60A };
		constexpr std::uint32_t m_bSaveRestore{ 0x60B };
		constexpr std::uint32_t m_bSavedIsPlaying{ 0x60C };
		constexpr std::uint32_t m_flSavedElapsedTime{ 0x610 };
		constexpr std::uint32_t m_iszSourceEntityName{ 0x618 };
		constexpr std::uint32_t m_iszAttachmentName{ 0x620 };
		constexpr std::uint32_t m_onGUIDChanged{ 0x628 };
		constexpr std::uint32_t m_onSoundFinished{ 0x648 };
		constexpr std::uint32_t m_flClientCullRadius{ 0x660 };
		constexpr std::uint32_t m_iszSoundName{ 0x690 };
		constexpr std::uint32_t m_hSource{ 0x6AC };
		constexpr std::uint32_t m_nEntityIndexSelection{ 0x6B0 };

	} // namespace c_soundevententity

	namespace c_soundeventobbentity {

		constexpr std::uint32_t m_vMins{ 0x6B8 };
		constexpr std::uint32_t m_vMaxs{ 0x6C4 };

	} // namespace c_soundeventobbentity

	namespace c_soundeventpathcornerentity {

		constexpr std::uint32_t m_vecCornerPairsNetworked{ 0x6B8 };

	} // namespace c_soundeventpathcornerentity

	namespace c_soundeventsphereentity {

		constexpr std::uint32_t m_flRadius{ 0x6B8 };

	} // namespace c_soundeventsphereentity

	namespace c_soundopvarsetpointbase {

		constexpr std::uint32_t m_iszStackName{ 0x608 };
		constexpr std::uint32_t m_iszOperatorName{ 0x610 };
		constexpr std::uint32_t m_iszOpvarName{ 0x618 };
		constexpr std::uint32_t m_iOpvarIndex{ 0x620 };
		constexpr std::uint32_t m_bUseAutoCompare{ 0x624 };
		constexpr std::uint32_t m_bFastRefresh{ 0x625 };

	} // namespace c_soundopvarsetpointbase

	namespace c_spotlightend {

		constexpr std::uint32_t m_flLightScale{ 0xE88 };
		constexpr std::uint32_t m_Radius{ 0xE8C };

	} // namespace c_spotlightend

	namespace c_sprite {

		constexpr std::uint32_t m_hSpriteMaterial{ 0xE88 };
		constexpr std::uint32_t m_hAttachedToEntity{ 0xE90 };
		constexpr std::uint32_t m_nAttachment{ 0xE94 };
		constexpr std::uint32_t m_flSpriteFramerate{ 0xE98 };
		constexpr std::uint32_t m_flFrame{ 0xE9C };
		constexpr std::uint32_t m_flDieTime{ 0xEA0 };
		constexpr std::uint32_t m_nBrightness{ 0xEB0 };
		constexpr std::uint32_t m_flBrightnessDuration{ 0xEB4 };
		constexpr std::uint32_t m_flSpriteScale{ 0xEB8 };
		constexpr std::uint32_t m_flScaleDuration{ 0xEBC };
		constexpr std::uint32_t m_bWorldSpaceScale{ 0xEC0 };
		constexpr std::uint32_t m_flGlowProxySize{ 0xEC4 };
		constexpr std::uint32_t m_flHDRColorScale{ 0xEC8 };
		constexpr std::uint32_t m_flLastTime{ 0xECC };
		constexpr std::uint32_t m_flMaxFrame{ 0xED0 };
		constexpr std::uint32_t m_flStartScale{ 0xED4 };
		constexpr std::uint32_t m_flDestScale{ 0xED8 };
		constexpr std::uint32_t m_flScaleTimeStart{ 0xEDC };
		constexpr std::uint32_t m_nStartBrightness{ 0xEE0 };
		constexpr std::uint32_t m_nDestBrightness{ 0xEE4 };
		constexpr std::uint32_t m_flBrightnessTimeStart{ 0xEE8 };
		constexpr std::uint32_t m_nSpriteWidth{ 0xEF8 };
		constexpr std::uint32_t m_nSpriteHeight{ 0xEFC };

	} // namespace c_sprite

	namespace c_stattrakmodule {

		constexpr std::uint32_t m_bKnife{ 0x1170 };

	} // namespace c_stattrakmodule

	namespace c_team {

		constexpr std::uint32_t m_aPlayerControllers{ 0x608 };
		constexpr std::uint32_t m_aPlayers{ 0x620 };
		constexpr std::uint32_t m_iScore{ 0x638 };
		constexpr std::uint32_t m_szTeamname{ 0x63C };

	} // namespace c_team

	namespace c_texturebasedanimatable {

		constexpr std::uint32_t m_bLoop{ 0xE88 };
		constexpr std::uint32_t m_flFPS{ 0xE8C };
		constexpr std::uint32_t m_hPositionKeys{ 0xE90 };
		constexpr std::uint32_t m_hRotationKeys{ 0xE98 };
		constexpr std::uint32_t m_vAnimationBoundsMin{ 0xEA0 };
		constexpr std::uint32_t m_vAnimationBoundsMax{ 0xEAC };
		constexpr std::uint32_t m_flStartTime{ 0xEB8 };
		constexpr std::uint32_t m_flStartFrame{ 0xEBC };

	} // namespace c_texturebasedanimatable

	namespace c_tonemapcontroller2 {

		constexpr std::uint32_t m_flAutoExposureMin{ 0x608 };
		constexpr std::uint32_t m_flAutoExposureMax{ 0x60C };
		constexpr std::uint32_t m_flExposureAdaptationSpeedUp{ 0x610 };
		constexpr std::uint32_t m_flExposureAdaptationSpeedDown{ 0x614 };
		constexpr std::uint32_t m_flTonemapEVSmoothingRange{ 0x618 };

	} // namespace c_tonemapcontroller2

	namespace c_triggerbuoyancy {

		constexpr std::uint32_t m_BuoyancyHelper{ 0xF58 };
		constexpr std::uint32_t m_flFluidDensity{ 0x1070 };

	} // namespace c_triggerbuoyancy

	namespace c_triggerphysics {

		constexpr std::uint32_t m_gravityScale{ 0xF58 };
		constexpr std::uint32_t m_linearLimit{ 0xF5C };
		constexpr std::uint32_t m_linearDamping{ 0xF60 };
		constexpr std::uint32_t m_angularLimit{ 0xF64 };
		constexpr std::uint32_t m_angularDamping{ 0xF68 };
		constexpr std::uint32_t m_linearForce{ 0xF6C };
		constexpr std::uint32_t m_flFrequency{ 0xF70 };
		constexpr std::uint32_t m_flDampingRatio{ 0xF74 };
		constexpr std::uint32_t m_vecLinearForcePointAt{ 0xF78 };
		constexpr std::uint32_t m_bCollapseToForcePoint{ 0xF84 };
		constexpr std::uint32_t m_vecLinearForcePointAtWorld{ 0xF88 };
		constexpr std::uint32_t m_vecLinearForceDirection{ 0xF94 };
		constexpr std::uint32_t m_bConvertToDebrisWhenPossible{ 0xFA0 };

	} // namespace c_triggerphysics

	namespace c_votecontroller {

		constexpr std::uint32_t m_iActiveIssueIndex{ 0x618 };
		constexpr std::uint32_t m_iOnlyTeamToVote{ 0x61C };
		constexpr std::uint32_t m_nVoteOptionCount{ 0x620 };
		constexpr std::uint32_t m_nPotentialVotes{ 0x634 };
		constexpr std::uint32_t m_bVotesDirty{ 0x638 };
		constexpr std::uint32_t m_bTypeDirty{ 0x639 };
		constexpr std::uint32_t m_bIsYesNoVote{ 0x63A };

	} // namespace c_votecontroller

	namespace c_weaponbaseitem {

		constexpr std::uint32_t m_bSequenceInProgress{ 0x1F40 };
		constexpr std::uint32_t m_bRedraw{ 0x1F41 };

	} // namespace c_weaponbaseitem

	namespace c_weaponcz75a {

		constexpr std::uint32_t m_bMagazineRemoved{ 0x1F70 };

	} // namespace c_weaponcz75a

	namespace c_weapontaser {

		constexpr std::uint32_t m_fFireTime{ 0x1F70 };
		constexpr std::uint32_t m_nLastAttackTick{ 0x1F74 };

	} // namespace c_weapontaser

	namespace canimgraphcontrollerbase {

		constexpr std::uint32_t m_hExternalGraph{ 0x18 };

	} // namespace canimgraphcontrollerbase

	namespace canimgraphcontrollermanager {

		constexpr std::uint32_t m_controllers{ 0x0 };
		constexpr std::uint32_t m_bGraphBindingsCreated{ 0xA8 };

	} // namespace canimgraphcontrollermanager

	namespace canimgraphnetworkedvariables {

		constexpr std::uint32_t m_PredNetBoolVariables{ 0x8 };
		constexpr std::uint32_t m_PredNetByteVariables{ 0x20 };
		constexpr std::uint32_t m_PredNetUInt16Variables{ 0x38 };
		constexpr std::uint32_t m_PredNetIntVariables{ 0x50 };
		constexpr std::uint32_t m_PredNetUInt32Variables{ 0x68 };
		constexpr std::uint32_t m_PredNetUInt64Variables{ 0x80 };
		constexpr std::uint32_t m_PredNetFloatVariables{ 0x98 };
		constexpr std::uint32_t m_PredNetVectorVariables{ 0xB0 };
		constexpr std::uint32_t m_PredNetQuaternionVariables{ 0xC8 };
		constexpr std::uint32_t m_PredNetGlobalSymbolVariables{ 0xE0 };
		constexpr std::uint32_t m_OwnerOnlyPredNetBoolVariables{ 0xF8 };
		constexpr std::uint32_t m_OwnerOnlyPredNetByteVariables{ 0x110 };
		constexpr std::uint32_t m_OwnerOnlyPredNetUInt16Variables{ 0x128 };
		constexpr std::uint32_t m_OwnerOnlyPredNetIntVariables{ 0x140 };
		constexpr std::uint32_t m_OwnerOnlyPredNetUInt32Variables{ 0x158 };
		constexpr std::uint32_t m_OwnerOnlyPredNetUInt64Variables{ 0x170 };
		constexpr std::uint32_t m_OwnerOnlyPredNetFloatVariables{ 0x188 };
		constexpr std::uint32_t m_OwnerOnlyPredNetVectorVariables{ 0x1A0 };
		constexpr std::uint32_t m_OwnerOnlyPredNetQuaternionVariables{ 0x1B8 };
		constexpr std::uint32_t m_OwnerOnlyPredNetGlobalSymbolVariables{ 0x1D0 };
		constexpr std::uint32_t m_nBoolVariablesCount{ 0x1E8 };
		constexpr std::uint32_t m_nOwnerOnlyBoolVariablesCount{ 0x1EC };
		constexpr std::uint32_t m_nRandomSeedOffset{ 0x1F0 };
		constexpr std::uint32_t m_flLastTeleportTime{ 0x1F4 };

	} // namespace canimgraphnetworkedvariables

	namespace cattributelist {

		constexpr std::uint32_t m_Attributes{ 0x8 };
		constexpr std::uint32_t m_pManager{ 0x70 };

	} // namespace cattributelist

	namespace cattributemanager {

		constexpr std::uint32_t m_Providers{ 0x8 };
		constexpr std::uint32_t m_iReapplyProvisionParity{ 0x20 };
		constexpr std::uint32_t m_hOuter{ 0x24 };
		constexpr std::uint32_t m_bPreventLoopback{ 0x28 };
		constexpr std::uint32_t m_ProviderType{ 0x2C };
		constexpr std::uint32_t m_CachedResults{ 0x30 };

	} // namespace cattributemanager

	namespace cattributemanager__cached_attribute_float_t {

		constexpr std::uint32_t flIn{ 0x0 };
		constexpr std::uint32_t iAttribHook{ 0x8 };
		constexpr std::uint32_t flOut{ 0x10 };

	} // namespace cattributemanager__cached_attribute_float_t

	namespace cbaseanimgraph {

		constexpr std::uint32_t m_graphControllerManager{ 0xE88 };
		constexpr std::uint32_t m_pMainGraphController{ 0xF38 };
		constexpr std::uint32_t m_bInitiallyPopulateInterpHistory{ 0xF40 };
		constexpr std::uint32_t m_bSuppressAnimEventSounds{ 0xF42 };
		constexpr std::uint32_t m_bAnimGraphUpdateEnabled{ 0xF50 };
		constexpr std::uint32_t m_flMaxSlopeDistance{ 0xF54 };
		constexpr std::uint32_t m_vLastSlopeCheckPos{ 0xF58 };
		constexpr std::uint32_t m_nAnimGraphUpdateId{ 0xF64 };
		constexpr std::uint32_t m_bAnimationUpdateScheduled{ 0xF68 };
		constexpr std::uint32_t m_vecForce{ 0xF6C };
		constexpr std::uint32_t m_nForceBone{ 0xF78 };
		constexpr std::uint32_t m_pClientsideRagdoll{ 0xF80 };
		constexpr std::uint32_t m_bBuiltRagdoll{ 0xF88 };
		constexpr std::uint32_t m_RagdollPose{ 0xFA0 };
		constexpr std::uint32_t m_bRagdollEnabled{ 0xFE8 };
		constexpr std::uint32_t m_bRagdollClientSide{ 0xFE9 };
		constexpr std::uint32_t m_bHasAnimatedMaterialAttributes{ 0xFF8 };

	} // namespace cbaseanimgraph

	namespace cbaseanimgraphcontroller {

		constexpr std::uint32_t m_nAnimationAlgorithm{ 0x18 };
		constexpr std::uint32_t m_animGraphNetworkedVars{ 0x20 };
		constexpr std::uint32_t m_pAnimGraphInstance{ 0x14B0 };
		constexpr std::uint32_t m_nNextExternalGraphHandle{ 0x1510 };
		constexpr std::uint32_t m_vecSecondarySkeletonNames{ 0x1518 };
		constexpr std::uint32_t m_vecSecondarySkeletons{ 0x1530 };
		constexpr std::uint32_t m_nSecondarySkeletonMasterCount{ 0x1548 };
		constexpr std::uint32_t m_flSoundSyncTime{ 0x1550 };
		constexpr std::uint32_t m_nActiveIKChainMask{ 0x1554 };
		constexpr std::uint32_t m_hSequence{ 0x15A8 };
		constexpr std::uint32_t m_flSeqStartTime{ 0x15AC };
		constexpr std::uint32_t m_flSeqFixedCycle{ 0x15B0 };
		constexpr std::uint32_t m_nAnimLoopMode{ 0x15B4 };
		constexpr std::uint32_t m_flPlaybackRate{ 0x15B8 };
		constexpr std::uint32_t m_nNotifyState{ 0x15C4 };
		constexpr std::uint32_t m_bNetworkedAnimationInputsChanged{ 0x15C5 };
		constexpr std::uint32_t m_bNetworkedSequenceChanged{ 0x15C6 };
		constexpr std::uint32_t m_bLastUpdateSkipped{ 0x15C7 };
		constexpr std::uint32_t m_bSequenceFinished{ 0x15C8 };
		constexpr std::uint32_t m_nPrevAnimUpdateTick{ 0x15CC };
		constexpr std::uint32_t m_hGraphDefinitionAG2{ 0x1868 };
		constexpr std::uint32_t m_serializedPoseRecipeAG2{ 0x1870 };
		constexpr std::uint32_t m_nSerializePoseRecipeSizeAG2{ 0x1888 };
		constexpr std::uint32_t m_nSerializePoseRecipeVersionAG2{ 0x188C };
		constexpr std::uint32_t m_nServerGraphInstanceIteration{ 0x1890 };
		constexpr std::uint32_t m_nServerSerializationContextIteration{ 0x1894 };
		constexpr std::uint32_t m_primaryGraphId{ 0x1898 };
		constexpr std::uint32_t m_vecExternalGraphIds{ 0x18A0 };
		constexpr std::uint32_t m_vecExternalClipIds{ 0x18B8 };
		constexpr std::uint32_t m_sAnimGraph2Identifier{ 0x18D0 };
		constexpr std::uint32_t m_vecExternalGraphs{ 0x1AF8 };
		constexpr std::uint32_t m_nPrevAnimationAlgorithm{ 0x1B31 };

	} // namespace cbaseanimgraphcontroller

	namespace cbasefilter {

		constexpr std::uint32_t m_bNegated{ 0x608 };
		constexpr std::uint32_t m_OnPass{ 0x610 };
		constexpr std::uint32_t m_OnFail{ 0x628 };

	} // namespace cbasefilter

	namespace cbaseplayercontroller {

		constexpr std::uint32_t m_CommandContext{ 0x610 };
		constexpr std::uint32_t m_nInButtonsWhichAreToggles{ 0x6B8 };
		constexpr std::uint32_t m_nTickBase{ 0x6C0 };
		constexpr std::uint32_t m_hPawn{ 0x6C4 };
		constexpr std::uint32_t m_bKnownTeamMismatch{ 0x6C8 };
		constexpr std::uint32_t m_hPredictedPawn{ 0x6CC };
		constexpr std::uint32_t m_nSplitScreenSlot{ 0x6D0 };
		constexpr std::uint32_t m_hSplitOwner{ 0x6D4 };
		constexpr std::uint32_t m_hSplitScreenPlayers{ 0x6D8 };
		constexpr std::uint32_t m_bIsHLTV{ 0x6F0 };
		constexpr std::uint32_t m_iConnected{ 0x6F4 };
		constexpr std::uint32_t m_iszPlayerName{ 0x6F8 };
		constexpr std::uint32_t m_steamID{ 0x780 };
		constexpr std::uint32_t m_bIsLocalPlayerController{ 0x788 };
		constexpr std::uint32_t m_bNoClipEnabled{ 0x789 };
		constexpr std::uint32_t m_iDesiredFOV{ 0x78C };

	} // namespace cbaseplayercontroller

	namespace cbaseplayervdata {

		constexpr std::uint32_t m_sModelName{ 0x28 };
		constexpr std::uint32_t m_flHeadDamageMultiplier{ 0x108 };
		constexpr std::uint32_t m_flChestDamageMultiplier{ 0x118 };
		constexpr std::uint32_t m_flStomachDamageMultiplier{ 0x128 };
		constexpr std::uint32_t m_flArmDamageMultiplier{ 0x138 };
		constexpr std::uint32_t m_flLegDamageMultiplier{ 0x148 };
		constexpr std::uint32_t m_flHoldBreathTime{ 0x158 };
		constexpr std::uint32_t m_flDrowningDamageInterval{ 0x15C };
		constexpr std::uint32_t m_nDrowningDamageInitial{ 0x160 };
		constexpr std::uint32_t m_nDrowningDamageMax{ 0x164 };
		constexpr std::uint32_t m_nWaterSpeed{ 0x168 };
		constexpr std::uint32_t m_flUseRange{ 0x16C };
		constexpr std::uint32_t m_flUseAngleTolerance{ 0x170 };
		constexpr std::uint32_t m_flCrouchTime{ 0x174 };

	} // namespace cbaseplayervdata

	namespace cbaseplayerweaponvdata {

		constexpr std::uint32_t m_szWorldModel{ 0x28 };
		constexpr std::uint32_t m_sToolsOnlyOwnerModelName{ 0x108 };
		constexpr std::uint32_t m_bBuiltRightHanded{ 0x1E8 };
		constexpr std::uint32_t m_bAllowFlipping{ 0x1E9 };
		constexpr std::uint32_t m_sMuzzleAttachment{ 0x1F0 };
		constexpr std::uint32_t m_szMuzzleFlashParticle{ 0x210 };
		constexpr std::uint32_t m_szMuzzleFlashParticleConfig{ 0x2F0 };
		constexpr std::uint32_t m_szBarrelSmokeParticle{ 0x2F8 };
		constexpr std::uint32_t m_nMuzzleSmokeShotThreshold{ 0x3D8 };
		constexpr std::uint32_t m_flMuzzleSmokeTimeout{ 0x3DC };
		constexpr std::uint32_t m_flMuzzleSmokeDecrementRate{ 0x3E0 };
		constexpr std::uint32_t m_bGenerateMuzzleLight{ 0x3E4 };
		constexpr std::uint32_t m_bLinkedCooldowns{ 0x3E5 };
		constexpr std::uint32_t m_iFlags{ 0x3E6 };
		constexpr std::uint32_t m_iWeight{ 0x3E8 };
		constexpr std::uint32_t m_bAutoSwitchTo{ 0x3EC };
		constexpr std::uint32_t m_bAutoSwitchFrom{ 0x3ED };
		constexpr std::uint32_t m_nPrimaryAmmoType{ 0x3EE };
		constexpr std::uint32_t m_nSecondaryAmmoType{ 0x3EF };
		constexpr std::uint32_t m_iMaxClip1{ 0x3F0 };
		constexpr std::uint32_t m_iMaxClip2{ 0x3F4 };
		constexpr std::uint32_t m_iDefaultClip1{ 0x3F8 };
		constexpr std::uint32_t m_iDefaultClip2{ 0x3FC };
		constexpr std::uint32_t m_bReserveAmmoAsClips{ 0x400 };
		constexpr std::uint32_t m_bTreatAsSingleClip{ 0x401 };
		constexpr std::uint32_t m_bKeepLoadedAmmo{ 0x402 };
		constexpr std::uint32_t m_iRumbleEffect{ 0x404 };
		constexpr std::uint32_t m_flDropSpeed{ 0x408 };
		constexpr std::uint32_t m_iSlot{ 0x40C };
		constexpr std::uint32_t m_iPosition{ 0x410 };
		constexpr std::uint32_t m_aShootSounds{ 0x418 };

	} // namespace cbaseplayerweaponvdata

	namespace cbaseprop {

		constexpr std::uint32_t m_bModelOverrodeBlockLOS{ 0x1168 };
		constexpr std::uint32_t m_iShapeType{ 0x116C };
		constexpr std::uint32_t m_bConformToCollisionBounds{ 0x1170 };
		constexpr std::uint32_t m_mPreferredCatchTransform{ 0x1180 };

	} // namespace cbaseprop

	namespace cbodycomponent {

		constexpr std::uint32_t m_pSceneNode{ 0x8 };
		constexpr std::uint32_t __m_pChainEntity{ 0x48 };

	} // namespace cbodycomponent

	namespace cbodycomponentbaseanimgraph {

		constexpr std::uint32_t m_animationController{ 0x550 };

	} // namespace cbodycomponentbaseanimgraph

	namespace cbodycomponentpoint {

		constexpr std::uint32_t m_sceneNode{ 0x80 };

	} // namespace cbodycomponentpoint

	namespace cbodycomponentskeletoninstance {

		constexpr std::uint32_t m_skeletonInstance{ 0x80 };

	} // namespace cbodycomponentskeletoninstance

	namespace cbombtarget {

		constexpr std::uint32_t m_bBombPlantedHere{ 0xF58 };

	} // namespace cbombtarget

	namespace cbreakablestagehelper {

		constexpr std::uint32_t m_nCurrentStage{ 0x8 };
		constexpr std::uint32_t m_nStageCount{ 0xC };

	} // namespace cbreakablestagehelper

	namespace cbuoyancyhelper {

		constexpr std::uint32_t m_nFluidType{ 0x18 };
		constexpr std::uint32_t m_flFluidDensity{ 0x1C };
		constexpr std::uint32_t m_flNeutrallyBuoyantGravity{ 0x20 };
		constexpr std::uint32_t m_flNeutrallyBuoyantLinearDamping{ 0x24 };
		constexpr std::uint32_t m_flNeutrallyBuoyantAngularDamping{ 0x28 };
		constexpr std::uint32_t m_bNeutrallyBuoyant{ 0x2C };
		constexpr std::uint32_t m_vecFractionOfWheelSubmergedForWheelFriction{ 0x30 };
		constexpr std::uint32_t m_vecWheelFrictionScales{ 0x48 };
		constexpr std::uint32_t m_vecFractionOfWheelSubmergedForWheelDrag{ 0x60 };
		constexpr std::uint32_t m_vecWheelDrag{ 0x78 };

	} // namespace cbuoyancyhelper

	namespace ccitadelsoundopvarsetobb {

		constexpr std::uint32_t m_iszStackName{ 0x620 };
		constexpr std::uint32_t m_iszOperatorName{ 0x628 };
		constexpr std::uint32_t m_iszOpvarName{ 0x630 };
		constexpr std::uint32_t m_vDistanceInnerMins{ 0x638 };
		constexpr std::uint32_t m_vDistanceInnerMaxs{ 0x644 };
		constexpr std::uint32_t m_vDistanceOuterMins{ 0x650 };
		constexpr std::uint32_t m_vDistanceOuterMaxs{ 0x65C };
		constexpr std::uint32_t m_nAABBDirection{ 0x668 };

	} // namespace ccitadelsoundopvarsetobb

	namespace cclientalphaproperty {

		constexpr std::uint32_t m_bAlphaOverride{ 0x0 };
		constexpr std::uint32_t m_bShadowAlphaOverride{ 0x0 };
		constexpr std::uint32_t m_nDesyncOffset{ 0x0 };
		constexpr std::uint32_t m_nRenderFX{ 0x0 };
		constexpr std::uint32_t m_nRenderMode{ 0x0 };
		constexpr std::uint32_t m_nDistFadeStart{ 0x10 };
		constexpr std::uint32_t m_nDistFadeEnd{ 0x12 };
		constexpr std::uint32_t m_nAlpha{ 0x17 };
		constexpr std::uint32_t m_flFadeScale{ 0x18 };
		constexpr std::uint32_t m_flRenderFxStartTime{ 0x1C };
		constexpr std::uint32_t m_flRenderFxDuration{ 0x20 };

	} // namespace cclientalphaproperty

	namespace ccollisionproperty {

		constexpr std::uint32_t m_collisionAttribute{ 0x10 };
		constexpr std::uint32_t m_vecMins{ 0x40 };
		constexpr std::uint32_t m_vecMaxs{ 0x4C };
		constexpr std::uint32_t m_usSolidFlags{ 0x5A };
		constexpr std::uint32_t m_nSolidType{ 0x5B };
		constexpr std::uint32_t m_triggerBloat{ 0x5C };
		constexpr std::uint32_t m_nSurroundType{ 0x5D };
		constexpr std::uint32_t m_CollisionGroup{ 0x5E };
		constexpr std::uint32_t m_nEnablePhysics{ 0x5F };
		constexpr std::uint32_t m_flBoundingRadius{ 0x60 };
		constexpr std::uint32_t m_vecSpecifiedSurroundingMins{ 0x64 };
		constexpr std::uint32_t m_vecSpecifiedSurroundingMaxs{ 0x70 };
		constexpr std::uint32_t m_vecSurroundingMaxs{ 0x7C };
		constexpr std::uint32_t m_vecSurroundingMins{ 0x88 };
		constexpr std::uint32_t m_vCapsuleCenter1{ 0x94 };
		constexpr std::uint32_t m_vCapsuleCenter2{ 0xA0 };
		constexpr std::uint32_t m_flCapsuleRadius{ 0xAC };

	} // namespace ccollisionproperty

	namespace ccompositematerialeditordoc {

		constexpr std::uint32_t m_nVersion{ 0x8 };
		constexpr std::uint32_t m_Points{ 0x10 };
		constexpr std::uint32_t m_KVthumbnail{ 0x28 };

	} // namespace ccompositematerialeditordoc

	namespace ccopyrecipientfilter {

		constexpr std::uint32_t m_Flags{ 0x8 };
		constexpr std::uint32_t m_Recipients{ 0x10 };
		constexpr std::uint32_t m_slotPlayerExcludedDueToPrediction{ 0x30 };

	} // namespace ccopyrecipientfilter

	namespace ccs2chickengraphcontroller {

		constexpr std::uint32_t m_action{ 0x90 };
		constexpr std::uint32_t m_actionSubtype{ 0xA8 };
		constexpr std::uint32_t m_bActionReset{ 0xC0 };
		constexpr std::uint32_t m_idleVariation{ 0xE0 };
		constexpr std::uint32_t m_runVariation{ 0xF8 };
		constexpr std::uint32_t m_panicVariation{ 0x110 };
		constexpr std::uint32_t m_squatVariation{ 0x128 };
		constexpr std::uint32_t m_bInWater{ 0x140 };
		constexpr std::uint32_t m_bHasActionCompletedEvent{ 0x158 };
		constexpr std::uint32_t m_bWaitingForCompletedEvent{ 0x159 };

	} // namespace ccs2chickengraphcontroller

	namespace ccs2weapongraphcontroller {

		constexpr std::uint32_t m_action{ 0x90 };
		constexpr std::uint32_t m_bActionReset{ 0xA8 };
		constexpr std::uint32_t m_flWeaponActionSpeedScale{ 0xC0 };
		constexpr std::uint32_t m_weaponCategory{ 0xD8 };
		constexpr std::uint32_t m_weaponType{ 0xF0 };
		constexpr std::uint32_t m_weaponExtraInfo{ 0x108 };
		constexpr std::uint32_t m_flWeaponAmmo{ 0x120 };
		constexpr std::uint32_t m_flWeaponAmmoMax{ 0x138 };
		constexpr std::uint32_t m_flWeaponAmmoReserve{ 0x150 };
		constexpr std::uint32_t m_bWeaponIsSilenced{ 0x168 };
		constexpr std::uint32_t m_flWeaponIronsightAmount{ 0x180 };
		constexpr std::uint32_t m_bIsUsingLegacyModel{ 0x198 };
		constexpr std::uint32_t m_idleVariation{ 0x1B0 };
		constexpr std::uint32_t m_deployVariation{ 0x1C8 };
		constexpr std::uint32_t m_attackType{ 0x1E0 };
		constexpr std::uint32_t m_attackThrowStrength{ 0x1F8 };
		constexpr std::uint32_t m_flAttackVariation{ 0x210 };
		constexpr std::uint32_t m_inspectVariation{ 0x228 };
		constexpr std::uint32_t m_inspectExtraInfo{ 0x240 };
		constexpr std::uint32_t m_reloadStage{ 0x258 };

	} // namespace ccs2weapongraphcontroller

	namespace ccsgamemoderules {

		constexpr std::uint32_t __m_pChainEntity{ 0x8 };

	} // namespace ccsgamemoderules

	namespace ccsgamemoderules_armsrace {

		constexpr std::uint32_t m_WeaponSequence{ 0x30 };

	} // namespace ccsgamemoderules_armsrace

	namespace ccsgamemoderules_deathmatch {

		constexpr std::uint32_t m_flDMBonusStartTime{ 0x30 };
		constexpr std::uint32_t m_flDMBonusTimeLength{ 0x34 };
		constexpr std::uint32_t m_sDMBonusWeapon{ 0x38 };

	} // namespace ccsgamemoderules_deathmatch

	namespace ccsobserver_observerservices {

		constexpr std::uint32_t m_obsInterpState{ 0x64 };

	} // namespace ccsobserver_observerservices

	namespace ccsplayer_actiontrackingservices {

		constexpr std::uint32_t m_hLastWeaponBeforeC4AutoSwitch{ 0x48 };
		constexpr std::uint32_t m_bIsRescuing{ 0x4C };
		constexpr std::uint32_t m_weaponPurchasesThisMatch{ 0x50 };
		constexpr std::uint32_t m_weaponPurchasesThisRound{ 0xC0 };

	} // namespace ccsplayer_actiontrackingservices

	namespace ccsplayer_bulletservices {

		constexpr std::uint32_t m_totalHitsOnServer{ 0x48 };

	} // namespace ccsplayer_bulletservices

	namespace ccsplayer_buyservices {

		constexpr std::uint32_t m_vecSellbackPurchaseEntries{ 0x48 };

	} // namespace ccsplayer_buyservices

	namespace ccsplayer_cameraservices {

		constexpr std::uint32_t m_flDeathCamTilt{ 0x2A8 };
		constexpr std::uint32_t m_vClientScopeInaccuracy{ 0x2B0 };

	} // namespace ccsplayer_cameraservices

	namespace ccsplayer_hostageservices {

		constexpr std::uint32_t m_hCarriedHostage{ 0x48 };
		constexpr std::uint32_t m_hCarriedHostageProp{ 0x4C };

	} // namespace ccsplayer_hostageservices

	namespace ccsplayer_itemservices {

		constexpr std::uint32_t m_bHasDefuser{ 0x48 };
		constexpr std::uint32_t m_bHasHelmet{ 0x49 };

	} // namespace ccsplayer_itemservices

	namespace ccsplayer_movementservices {

		constexpr std::uint32_t m_vecLadderNormal{ 0x270 };
		constexpr std::uint32_t m_nLadderSurfacePropIndex{ 0x27C };
		constexpr std::uint32_t m_bDucked{ 0x280 };
		constexpr std::uint32_t m_flDuckAmount{ 0x284 };
		constexpr std::uint32_t m_flDuckSpeed{ 0x288 };
		constexpr std::uint32_t m_bDuckOverride{ 0x28C };
		constexpr std::uint32_t m_bDesiresDuck{ 0x28D };
		constexpr std::uint32_t m_bDucking{ 0x28E };
		constexpr std::uint32_t m_flDuckOffset{ 0x290 };
		constexpr std::uint32_t m_nDuckTimeMsecs{ 0x294 };
		constexpr std::uint32_t m_nDuckJumpTimeMsecs{ 0x298 };
		constexpr std::uint32_t m_nJumpTimeMsecs{ 0x29C };
		constexpr std::uint32_t m_flLastDuckTime{ 0x2A0 };
		constexpr std::uint32_t m_vecLastPositionAtFullCrouchSpeed{ 0x2B0 };
		constexpr std::uint32_t m_duckUntilOnGround{ 0x2B8 };
		constexpr std::uint32_t m_bHasWalkMovedSinceLastJump{ 0x2B9 };
		constexpr std::uint32_t m_bInStuckTest{ 0x2BA };
		constexpr std::uint32_t m_nTraceCount{ 0x4C8 };
		constexpr std::uint32_t m_StuckLast{ 0x4CC };
		constexpr std::uint32_t m_bSpeedCropped{ 0x4D0 };
		constexpr std::uint32_t m_nOldWaterLevel{ 0x4D4 };
		constexpr std::uint32_t m_flWaterEntryTime{ 0x4D8 };
		constexpr std::uint32_t m_vecForward{ 0x4DC };
		constexpr std::uint32_t m_vecLeft{ 0x4E8 };
		constexpr std::uint32_t m_vecUp{ 0x4F4 };
		constexpr std::uint32_t m_nGameCodeHasMovedPlayerAfterCommand{ 0x500 };
		constexpr std::uint32_t m_fStashGrenadeParameterWhen{ 0x504 };
		constexpr std::uint32_t m_nButtonDownMaskPrev{ 0x508 };
		constexpr std::uint32_t m_flOffsetTickCompleteTime{ 0x510 };
		constexpr std::uint32_t m_flOffsetTickStashedSpeed{ 0x514 };
		constexpr std::uint32_t m_flStamina{ 0x518 };
		constexpr std::uint32_t m_flHeightAtJumpStart{ 0x51C };
		constexpr std::uint32_t m_flMaxJumpHeightThisJump{ 0x520 };
		constexpr std::uint32_t m_flMaxJumpHeightLastJump{ 0x524 };
		constexpr std::uint32_t m_flStaminaAtJumpStart{ 0x528 };
		constexpr std::uint32_t m_flVelMulAtJumpStart{ 0x52C };
		constexpr std::uint32_t m_flAccumulatedJumpError{ 0x530 };
		constexpr std::uint32_t m_LegacyJump{ 0x538 };
		constexpr std::uint32_t m_ModernJump{ 0x550 };
		constexpr std::uint32_t m_nLastJumpTick{ 0x588 };
		constexpr std::uint32_t m_flLastJumpFrac{ 0x58C };
		constexpr std::uint32_t m_flLastJumpVelocityZ{ 0x590 };
		constexpr std::uint32_t m_bJumpApexPending{ 0x594 };
		constexpr std::uint32_t m_flTicksSinceLastSurfingDetected{ 0x598 };
		constexpr std::uint32_t m_bWasSurfing{ 0x59C };
		constexpr std::uint32_t m_vecInputRotated{ 0x62C };

	} // namespace ccsplayer_movementservices

	namespace ccsplayer_pingservices {

		constexpr std::uint32_t m_hPlayerPing{ 0x48 };

	} // namespace ccsplayer_pingservices

	namespace ccsplayer_waterservices {

		constexpr std::uint32_t m_flWaterJumpTime{ 0x48 };
		constexpr std::uint32_t m_vecWaterJumpVel{ 0x4C };
		constexpr std::uint32_t m_flSwimSoundTime{ 0x58 };

	} // namespace ccsplayer_waterservices

	namespace ccsplayer_weaponservices {

		constexpr std::uint32_t m_flNextAttack{ 0xD0 };
		constexpr std::uint32_t m_bIsLookingAtWeapon{ 0xD4 };
		constexpr std::uint32_t m_bIsHoldingLookAtWeapon{ 0xD5 };
		constexpr std::uint32_t m_nOldTotalShootPositionHistoryCount{ 0xD8 };
		constexpr std::uint32_t m_nOldTotalInputHistoryCount{ 0x370 };
		constexpr std::uint32_t m_networkAnimTiming{ 0x1588 };
		constexpr std::uint32_t m_bBlockInspectUntilNextGraphUpdate{ 0x15A0 };

	} // namespace ccsplayer_weaponservices

	namespace ccsplayerbase_cameraservices {

		constexpr std::uint32_t m_iFOV{ 0x290 };
		constexpr std::uint32_t m_iFOVStart{ 0x294 };
		constexpr std::uint32_t m_flFOVTime{ 0x298 };
		constexpr std::uint32_t m_flFOVRate{ 0x29C };
		constexpr std::uint32_t m_hZoomOwner{ 0x2A0 };
		constexpr std::uint32_t m_flLastShotFOV{ 0x2A4 };

	} // namespace ccsplayerbase_cameraservices

	namespace ccsplayercontroller {

		constexpr std::uint32_t m_pInGameMoneyServices{ 0x808 };
		constexpr std::uint32_t m_pInventoryServices{ 0x810 };
		constexpr std::uint32_t m_pActionTrackingServices{ 0x818 };
		constexpr std::uint32_t m_pDamageServices{ 0x820 };
		constexpr std::uint32_t m_iPing{ 0x828 };
		constexpr std::uint32_t m_bHasCommunicationAbuseMute{ 0x82C };
		constexpr std::uint32_t m_uiCommunicationMuteFlags{ 0x830 };
		constexpr std::uint32_t m_szCrosshairCodes{ 0x838 };
		constexpr std::uint32_t m_iPendingTeamNum{ 0x840 };
		constexpr std::uint32_t m_flForceTeamTime{ 0x844 };
		constexpr std::uint32_t m_iCompTeammateColor{ 0x848 };
		constexpr std::uint32_t m_bEverPlayedOnTeam{ 0x84C };
		constexpr std::uint32_t m_flPreviousForceJoinTeamTime{ 0x850 };
		constexpr std::uint32_t m_szClan{ 0x858 };
		constexpr std::uint32_t m_sSanitizedPlayerName{ 0x860 };
		constexpr std::uint32_t m_iCoachingTeam{ 0x868 };
		constexpr std::uint32_t m_nPlayerDominated{ 0x870 };
		constexpr std::uint32_t m_nPlayerDominatingMe{ 0x878 };
		constexpr std::uint32_t m_iCompetitiveRanking{ 0x880 };
		constexpr std::uint32_t m_iCompetitiveWins{ 0x884 };
		constexpr std::uint32_t m_iCompetitiveRankType{ 0x888 };
		constexpr std::uint32_t m_iCompetitiveRankingPredicted_Win{ 0x88C };
		constexpr std::uint32_t m_iCompetitiveRankingPredicted_Loss{ 0x890 };
		constexpr std::uint32_t m_iCompetitiveRankingPredicted_Tie{ 0x894 };
		constexpr std::uint32_t m_nEndMatchNextMapVote{ 0x898 };
		constexpr std::uint32_t m_unActiveQuestId{ 0x89C };
		constexpr std::uint32_t m_rtActiveMissionPeriod{ 0x8A0 };
		constexpr std::uint32_t m_nQuestProgressReason{ 0x8A4 };
		constexpr std::uint32_t m_unPlayerTvControlFlags{ 0x8A8 };
		constexpr std::uint32_t m_iDraftIndex{ 0x8D8 };
		constexpr std::uint32_t m_msQueuedModeDisconnectionTimestamp{ 0x8DC };
		constexpr std::uint32_t m_uiAbandonRecordedReason{ 0x8E0 };
		constexpr std::uint32_t m_eNetworkDisconnectionReason{ 0x8E4 };
		constexpr std::uint32_t m_bCannotBeKicked{ 0x8E8 };
		constexpr std::uint32_t m_bEverFullyConnected{ 0x8E9 };
		constexpr std::uint32_t m_bAbandonAllowsSurrender{ 0x8EA };
		constexpr std::uint32_t m_bAbandonOffersInstantSurrender{ 0x8EB };
		constexpr std::uint32_t m_bDisconnection1MinWarningPrinted{ 0x8EC };
		constexpr std::uint32_t m_bScoreReported{ 0x8ED };
		constexpr std::uint32_t m_nDisconnectionTick{ 0x8F0 };
		constexpr std::uint32_t m_bControllingBot{ 0x900 };
		constexpr std::uint32_t m_bHasControlledBotThisRound{ 0x901 };
		constexpr std::uint32_t m_bHasBeenControlledByPlayerThisRound{ 0x902 };
		constexpr std::uint32_t m_nBotsControlledThisRound{ 0x904 };
		constexpr std::uint32_t m_bCanControlObservedBot{ 0x908 };
		constexpr std::uint32_t m_hPlayerPawn{ 0x90C };
		constexpr std::uint32_t m_hObserverPawn{ 0x910 };
		constexpr std::uint32_t m_bPawnIsAlive{ 0x914 };
		constexpr std::uint32_t m_iPawnHealth{ 0x918 };
		constexpr std::uint32_t m_iPawnArmor{ 0x91C };
		constexpr std::uint32_t m_bPawnHasDefuser{ 0x920 };
		constexpr std::uint32_t m_bPawnHasHelmet{ 0x921 };
		constexpr std::uint32_t m_nPawnCharacterDefIndex{ 0x922 };
		constexpr std::uint32_t m_iPawnLifetimeStart{ 0x924 };
		constexpr std::uint32_t m_iPawnLifetimeEnd{ 0x928 };
		constexpr std::uint32_t m_iPawnBotDifficulty{ 0x92C };
		constexpr std::uint32_t m_hOriginalControllerOfCurrentPawn{ 0x930 };
		constexpr std::uint32_t m_iScore{ 0x934 };
		constexpr std::uint32_t m_recentKillQueue{ 0x938 };
		constexpr std::uint32_t m_nFirstKill{ 0x940 };
		constexpr std::uint32_t m_nKillCount{ 0x941 };
		constexpr std::uint32_t m_bMvpNoMusic{ 0x942 };
		constexpr std::uint32_t m_eMvpReason{ 0x944 };
		constexpr std::uint32_t m_iMusicKitID{ 0x948 };
		constexpr std::uint32_t m_iMusicKitMVPs{ 0x94C };
		constexpr std::uint32_t m_iMVPs{ 0x950 };
		constexpr std::uint32_t m_bIsPlayerNameDirty{ 0x954 };
		constexpr std::uint32_t m_bFireBulletsSeedSynchronized{ 0x955 };

	} // namespace ccsplayercontroller

	namespace ccsplayercontroller_actiontrackingservices {

		constexpr std::uint32_t m_perRoundStats{ 0x40 };
		constexpr std::uint32_t m_matchStats{ 0xA8 };
		constexpr std::uint32_t m_iNumRoundKills{ 0x128 };
		constexpr std::uint32_t m_iNumRoundKillsHeadshots{ 0x12C };
		constexpr std::uint32_t m_flTotalRoundDamageDealt{ 0x130 };

	} // namespace ccsplayercontroller_actiontrackingservices

	namespace ccsplayercontroller_damageservices {

		constexpr std::uint32_t m_nSendUpdate{ 0x40 };
		constexpr std::uint32_t m_DamageList{ 0x48 };

	} // namespace ccsplayercontroller_damageservices

	namespace ccsplayercontroller_ingamemoneyservices {

		constexpr std::uint32_t m_iAccount{ 0x40 };
		constexpr std::uint32_t m_iStartAccount{ 0x44 };
		constexpr std::uint32_t m_iTotalCashSpent{ 0x48 };
		constexpr std::uint32_t m_iCashSpentThisRound{ 0x4C };

	} // namespace ccsplayercontroller_ingamemoneyservices

	namespace ccsplayercontroller_inventoryservices {

		constexpr std::uint32_t m_vecNetworkableLoadout{ 0x40 };
		constexpr std::uint32_t m_unMusicID{ 0x58 };
		constexpr std::uint32_t m_rank{ 0x5C };
		constexpr std::uint32_t m_nPersonaDataPublicLevel{ 0x74 };
		constexpr std::uint32_t m_nPersonaDataPublicCommendsLeader{ 0x78 };
		constexpr std::uint32_t m_nPersonaDataPublicCommendsTeacher{ 0x7C };
		constexpr std::uint32_t m_nPersonaDataPublicCommendsFriendly{ 0x80 };
		constexpr std::uint32_t m_nPersonaDataXpTrailLevel{ 0x84 };
		constexpr std::uint32_t m_vecServerAuthoritativeWeaponSlots{ 0x88 };

	} // namespace ccsplayercontroller_inventoryservices

	namespace ccsplayercontroller_inventoryservices__networkedloadoutslot_t {

		constexpr std::uint32_t pItem{ 0x0 };
		constexpr std::uint32_t team{ 0x8 };
		constexpr std::uint32_t slot{ 0xA };

	} // namespace ccsplayercontroller_inventoryservices__networkedloadoutslot_t

	namespace ccsplayerlegacyjump {

		constexpr std::uint32_t m_bOldJumpPressed{ 0x10 };
		constexpr std::uint32_t m_flJumpPressedTime{ 0x14 };

	} // namespace ccsplayerlegacyjump

	namespace ccsplayermodernjump {

		constexpr std::uint32_t m_nLastActualJumpPressTick{ 0x10 };
		constexpr std::uint32_t m_flLastActualJumpPressFrac{ 0x14 };
		constexpr std::uint32_t m_nLastUsableJumpPressTick{ 0x18 };
		constexpr std::uint32_t m_flLastUsableJumpPressFrac{ 0x1C };
		constexpr std::uint32_t m_nLastLandedTick{ 0x20 };
		constexpr std::uint32_t m_flLastLandedFrac{ 0x24 };
		constexpr std::uint32_t m_flLastLandedVelocityX{ 0x28 };
		constexpr std::uint32_t m_flLastLandedVelocityY{ 0x2C };
		constexpr std::uint32_t m_flLastLandedVelocityZ{ 0x30 };

	} // namespace ccsplayermodernjump

	namespace ccsweaponbasevdata {

		constexpr std::uint32_t m_WeaponType{ 0x440 };
		constexpr std::uint32_t m_WeaponCategory{ 0x444 };
		constexpr std::uint32_t m_szAnimSkeleton{ 0x448 };
		constexpr std::uint32_t m_vecMuzzlePos0{ 0x528 };
		constexpr std::uint32_t m_vecMuzzlePos1{ 0x534 };
		constexpr std::uint32_t m_szTracerParticle{ 0x540 };
		constexpr std::uint32_t m_GearSlot{ 0x620 };
		constexpr std::uint32_t m_GearSlotPosition{ 0x624 };
		constexpr std::uint32_t m_DefaultLoadoutSlot{ 0x628 };
		constexpr std::uint32_t m_nPrice{ 0x62C };
		constexpr std::uint32_t m_nKillAward{ 0x630 };
		constexpr std::uint32_t m_nPrimaryReserveAmmoMax{ 0x634 };
		constexpr std::uint32_t m_nSecondaryReserveAmmoMax{ 0x638 };
		constexpr std::uint32_t m_bMeleeWeapon{ 0x63C };
		constexpr std::uint32_t m_bHasBurstMode{ 0x63D };
		constexpr std::uint32_t m_bIsRevolver{ 0x63E };
		constexpr std::uint32_t m_bCannotShootUnderwater{ 0x63F };
		constexpr std::uint32_t m_szName{ 0x640 };
		constexpr std::uint32_t m_eSilencerType{ 0x648 };
		constexpr std::uint32_t m_nCrosshairMinDistance{ 0x64C };
		constexpr std::uint32_t m_nCrosshairDeltaDistance{ 0x650 };
		constexpr std::uint32_t m_bIsFullAuto{ 0x654 };
		constexpr std::uint32_t m_nNumBullets{ 0x658 };
		constexpr std::uint32_t m_bReloadsSingleShells{ 0x65C };
		constexpr std::uint32_t m_flCycleTime{ 0x660 };
		constexpr std::uint32_t m_flMaxSpeed{ 0x668 };
		constexpr std::uint32_t m_flSpread{ 0x670 };
		constexpr std::uint32_t m_flInaccuracyCrouch{ 0x678 };
		constexpr std::uint32_t m_flInaccuracyStand{ 0x680 };
		constexpr std::uint32_t m_flInaccuracyJump{ 0x688 };
		constexpr std::uint32_t m_flInaccuracyLand{ 0x690 };
		constexpr std::uint32_t m_flInaccuracyLadder{ 0x698 };
		constexpr std::uint32_t m_flInaccuracyFire{ 0x6A0 };
		constexpr std::uint32_t m_flInaccuracyMove{ 0x6A8 };
		constexpr std::uint32_t m_flRecoilAngle{ 0x6B0 };
		constexpr std::uint32_t m_flRecoilAngleVariance{ 0x6B8 };
		constexpr std::uint32_t m_flRecoilMagnitude{ 0x6C0 };
		constexpr std::uint32_t m_flRecoilMagnitudeVariance{ 0x6C8 };
		constexpr std::uint32_t m_nTracerFrequency{ 0x6D0 };
		constexpr std::uint32_t m_flInaccuracyJumpInitial{ 0x6D8 };
		constexpr std::uint32_t m_flInaccuracyJumpApex{ 0x6DC };
		constexpr std::uint32_t m_flInaccuracyReload{ 0x6E0 };
		constexpr std::uint32_t m_flDeployDuration{ 0x6E4 };
		constexpr std::uint32_t m_flDisallowAttackAfterReloadStartDuration{ 0x6E8 };
		constexpr std::uint32_t m_nBurstShotCount{ 0x6EC };
		constexpr std::uint32_t m_bAllowBurstHolster{ 0x6F0 };
		constexpr std::uint32_t m_nRecoilSeed{ 0x6F4 };
		constexpr std::uint32_t m_nSpreadSeed{ 0x6F8 };
		constexpr std::uint32_t m_flAttackMovespeedFactor{ 0x6FC };
		constexpr std::uint32_t m_flInaccuracyPitchShift{ 0x700 };
		constexpr std::uint32_t m_flInaccuracyAltSoundThreshold{ 0x704 };
		constexpr std::uint32_t m_szUseRadioSubtitle{ 0x708 };
		constexpr std::uint32_t m_bUnzoomsAfterShot{ 0x710 };
		constexpr std::uint32_t m_bHideViewModelWhenZoomed{ 0x711 };
		constexpr std::uint32_t m_nZoomLevels{ 0x714 };
		constexpr std::uint32_t m_nZoomFOV1{ 0x718 };
		constexpr std::uint32_t m_nZoomFOV2{ 0x71C };
		constexpr std::uint32_t m_flZoomTime0{ 0x720 };
		constexpr std::uint32_t m_flZoomTime1{ 0x724 };
		constexpr std::uint32_t m_flZoomTime2{ 0x728 };
		constexpr std::uint32_t m_flIronSightPullUpSpeed{ 0x72C };
		constexpr std::uint32_t m_flIronSightPutDownSpeed{ 0x730 };
		constexpr std::uint32_t m_flIronSightFOV{ 0x734 };
		constexpr std::uint32_t m_flIronSightPivotForward{ 0x738 };
		constexpr std::uint32_t m_flIronSightLooseness{ 0x73C };
		constexpr std::uint32_t m_nDamage{ 0x740 };
		constexpr std::uint32_t m_flHeadshotMultiplier{ 0x744 };
		constexpr std::uint32_t m_flArmorRatio{ 0x748 };
		constexpr std::uint32_t m_flPenetration{ 0x74C };
		constexpr std::uint32_t m_flRange{ 0x750 };
		constexpr std::uint32_t m_flRangeModifier{ 0x754 };
		constexpr std::uint32_t m_flFlinchVelocityModifierLarge{ 0x758 };
		constexpr std::uint32_t m_flFlinchVelocityModifierSmall{ 0x75C };
		constexpr std::uint32_t m_flRecoveryTimeCrouch{ 0x760 };
		constexpr std::uint32_t m_flRecoveryTimeStand{ 0x764 };
		constexpr std::uint32_t m_flRecoveryTimeCrouchFinal{ 0x768 };
		constexpr std::uint32_t m_flRecoveryTimeStandFinal{ 0x76C };
		constexpr std::uint32_t m_nRecoveryTransitionStartBullet{ 0x770 };
		constexpr std::uint32_t m_nRecoveryTransitionEndBullet{ 0x774 };
		constexpr std::uint32_t m_flThrowVelocity{ 0x778 };
		constexpr std::uint32_t m_vSmokeColor{ 0x77C };
		constexpr std::uint32_t m_szAnimClass{ 0x788 };

	} // namespace ccsweaponbasevdata

	namespace cdamagerecord {

		constexpr std::uint32_t m_PlayerDamager{ 0x30 };
		constexpr std::uint32_t m_PlayerRecipient{ 0x34 };
		constexpr std::uint32_t m_hPlayerControllerDamager{ 0x38 };
		constexpr std::uint32_t m_hPlayerControllerRecipient{ 0x3C };
		constexpr std::uint32_t m_szPlayerDamagerName{ 0x40 };
		constexpr std::uint32_t m_szPlayerRecipientName{ 0x48 };
		constexpr std::uint32_t m_DamagerXuid{ 0x50 };
		constexpr std::uint32_t m_RecipientXuid{ 0x58 };
		constexpr std::uint32_t m_flBulletsDamage{ 0x60 };
		constexpr std::uint32_t m_flDamage{ 0x64 };
		constexpr std::uint32_t m_flActualHealthRemoved{ 0x68 };
		constexpr std::uint32_t m_iNumHits{ 0x6C };
		constexpr std::uint32_t m_iLastBulletUpdate{ 0x70 };
		constexpr std::uint32_t m_bIsOtherEnemy{ 0x74 };
		constexpr std::uint32_t m_killType{ 0x75 };

	} // namespace cdamagerecord

	namespace cdecalgroupvdata {

		constexpr std::uint32_t m_vecOptions{ 0x0 };
		constexpr std::uint32_t m_flTotalProbability{ 0x18 };

	} // namespace cdecalgroupvdata

	namespace cdecalinstance {

		constexpr std::uint32_t m_sDecalGroup{ 0x0 };
		constexpr std::uint32_t m_hMaterial{ 0x8 };
		constexpr std::uint32_t m_sSequenceName{ 0x10 };
		constexpr std::uint32_t m_hEntity{ 0x14 };
		constexpr std::uint32_t m_nBoneIndex{ 0x18 };
		constexpr std::uint32_t m_nTriangleIndex{ 0x1C };
		constexpr std::uint32_t m_vPositionLS{ 0x20 };
		constexpr std::uint32_t m_vNormalLS{ 0x2C };
		constexpr std::uint32_t m_vSAxisLS{ 0x38 };
		constexpr std::uint32_t m_nFlags{ 0x44 };
		constexpr std::uint32_t m_Color{ 0x48 };
		constexpr std::uint32_t m_flWidth{ 0x4C };
		constexpr std::uint32_t m_flHeight{ 0x50 };
		constexpr std::uint32_t m_flDepth{ 0x54 };
		constexpr std::uint32_t m_transform{ 0x60 };
		constexpr std::uint32_t m_flAnimationScale{ 0x80 };
		constexpr std::uint32_t m_flAnimationStartTime{ 0x84 };
		constexpr std::uint32_t m_flPlaceTime{ 0x88 };
		constexpr std::uint32_t m_flFadeStartTime{ 0x8C };
		constexpr std::uint32_t m_flFadeDuration{ 0x90 };
		constexpr std::uint32_t m_flLightingOriginOffset{ 0x94 };
		constexpr std::uint32_t m_flBoundingRadiusSqr{ 0xA0 };
		constexpr std::uint32_t m_nSequenceIndex{ 0xA4 };
		constexpr std::uint32_t m_bIsAdjacent{ 0xA6 };
		constexpr std::uint32_t m_bDoDecalLightmapping{ 0xA7 };
		constexpr std::uint32_t m_nDecalRtEncoding{ 0xA8 };
		constexpr std::uint32_t m_bProjectToBackfaces{ 0xA9 };

	} // namespace cdecalinstance

	namespace cdestructiblepart {

		constexpr std::uint32_t m_DebugName{ 0x0 };
		constexpr std::uint32_t m_nHitGroup{ 0x8 };
		constexpr std::uint32_t m_bDisableHitGroupWhenDestroyed{ 0xC };
		constexpr std::uint32_t m_nOtherHitgroupsToDestroyWhenFullyDestructed{ 0x10 };
		constexpr std::uint32_t m_bOnlyDestroyWhenGibbing{ 0x28 };
		constexpr std::uint32_t m_sBodyGroupName{ 0x30 };
		constexpr std::uint32_t m_DamageLevels{ 0x38 };

	} // namespace cdestructiblepart

	namespace cdestructiblepart_damagelevel {

		constexpr std::uint32_t m_sName{ 0x0 };
		constexpr std::uint32_t m_sBreakablePieceName{ 0x8 };
		constexpr std::uint32_t m_nBodyGroupValue{ 0x10 };
		constexpr std::uint32_t m_nHealth{ 0x14 };
		constexpr std::uint32_t m_flCriticalDamagePercent{ 0x24 };
		constexpr std::uint32_t m_nDamagePassthroughType{ 0x28 };
		constexpr std::uint32_t m_nDestructionDeathBehavior{ 0x2C };
		constexpr std::uint32_t m_sCustomDeathHandshake{ 0x30 };
		constexpr std::uint32_t m_bShouldDestroyOnDeath{ 0x38 };
		constexpr std::uint32_t m_flDeathDestroyTime{ 0x3C };

	} // namespace cdestructiblepart_damagelevel

	namespace cdestructiblepartscomponent {

		constexpr std::uint32_t __m_pChainEntity{ 0x0 };
		constexpr std::uint32_t m_vecDamageTakenByHitGroup{ 0x48 };
		constexpr std::uint32_t m_hOwner{ 0x60 };

	} // namespace cdestructiblepartscomponent

	namespace cdestructiblepartssystemdata {

		constexpr std::uint32_t m_PartsDataByHitGroup{ 0x0 };
		constexpr std::uint32_t m_nMinMaxNumberHitGroupsToDestroyWhenGibbing{ 0x28 };

	} // namespace cdestructiblepartssystemdata

	namespace ceconitemattribute {

		constexpr std::uint32_t m_iAttributeDefinitionIndex{ 0x30 };
		constexpr std::uint32_t m_flValue{ 0x34 };
		constexpr std::uint32_t m_flInitialValue{ 0x38 };
		constexpr std::uint32_t m_nRefundableCurrency{ 0x3C };
		constexpr std::uint32_t m_bSetBonus{ 0x40 };

	} // namespace ceconitemattribute

	namespace ceffectdata {

		constexpr std::uint32_t m_vOrigin{ 0x8 };
		constexpr std::uint32_t m_vStart{ 0x14 };
		constexpr std::uint32_t m_vNormal{ 0x20 };
		constexpr std::uint32_t m_vAngles{ 0x2C };
		constexpr std::uint32_t m_hEntity{ 0x38 };
		constexpr std::uint32_t m_hOtherEntity{ 0x3C };
		constexpr std::uint32_t m_flScale{ 0x40 };
		constexpr std::uint32_t m_flMagnitude{ 0x44 };
		constexpr std::uint32_t m_flRadius{ 0x48 };
		constexpr std::uint32_t m_nSurfaceProp{ 0x4C };
		constexpr std::uint32_t m_nEffectIndex{ 0x50 };
		constexpr std::uint32_t m_nDamageType{ 0x58 };
		constexpr std::uint32_t m_nPenetrate{ 0x5C };
		constexpr std::uint32_t m_nMaterial{ 0x5E };
		constexpr std::uint32_t m_nHitBox{ 0x60 };
		constexpr std::uint32_t m_nColor{ 0x62 };
		constexpr std::uint32_t m_fFlags{ 0x63 };
		constexpr std::uint32_t m_nAttachmentIndex{ 0x64 };
		constexpr std::uint32_t m_nAttachmentName{ 0x68 };
		constexpr std::uint32_t m_iEffectName{ 0x6C };
		constexpr std::uint32_t m_nExplosionType{ 0x6E };

	} // namespace ceffectdata

	namespace centityattributetable {

		constexpr std::uint32_t m_Attributes{ 0x0 };
		constexpr std::uint32_t m_Names{ 0x28 };

	} // namespace centityattributetable

	namespace centitycomponenthelper {

		constexpr std::uint32_t m_flags{ 0x8 };
		constexpr std::uint32_t m_pInfo{ 0x10 };
		constexpr std::uint32_t m_nPriority{ 0x18 };
		constexpr std::uint32_t m_pNext{ 0x20 };

	} // namespace centitycomponenthelper

	namespace centityidentity {

		constexpr std::uint32_t m_nameStringableIndex{ 0x14 };
		constexpr std::uint32_t m_name{ 0x18 };
		constexpr std::uint32_t m_designerName{ 0x20 };
		constexpr std::uint32_t m_flags{ 0x30 };
		constexpr std::uint32_t m_worldGroupId{ 0x38 };
		constexpr std::uint32_t m_fDataObjectTypes{ 0x3C };
		constexpr std::uint32_t m_PathIndex{ 0x40 };
		constexpr std::uint32_t m_pAttributes{ 0x48 };
		constexpr std::uint32_t m_pPrev{ 0x50 };
		constexpr std::uint32_t m_pNext{ 0x58 };
		constexpr std::uint32_t m_pPrevByClass{ 0x60 };
		constexpr std::uint32_t m_pNextByClass{ 0x68 };

	} // namespace centityidentity

	namespace centityinstance {

		constexpr std::uint32_t m_iszPrivateVScripts{ 0x8 };
		constexpr std::uint32_t m_pEntity{ 0x10 };
		constexpr std::uint32_t m_CScriptComponent{ 0x30 };

	} // namespace centityinstance

	namespace cenvsoundscape {

		constexpr std::uint32_t m_OnPlay{ 0x608 };
		constexpr std::uint32_t m_flRadius{ 0x620 };
		constexpr std::uint32_t m_soundEventName{ 0x628 };
		constexpr std::uint32_t m_bOverrideWithEvent{ 0x630 };
		constexpr std::uint32_t m_soundscapeIndex{ 0x634 };
		constexpr std::uint32_t m_soundscapeEntityListId{ 0x638 };
		constexpr std::uint32_t m_positionNames{ 0x640 };
		constexpr std::uint32_t m_hProxySoundscape{ 0x680 };
		constexpr std::uint32_t m_bDisabled{ 0x684 };
		constexpr std::uint32_t m_soundscapeName{ 0x688 };
		constexpr std::uint32_t m_soundEventHash{ 0x690 };

	} // namespace cenvsoundscape

	namespace cenvsoundscapeproxy {

		constexpr std::uint32_t m_MainSoundscapeName{ 0x698 };

	} // namespace cenvsoundscapeproxy

	namespace cfilterattributeint {

		constexpr std::uint32_t m_sAttributeName{ 0x640 };

	} // namespace cfilterattributeint

	namespace cfilterclass {

		constexpr std::uint32_t m_iFilterClass{ 0x640 };

	} // namespace cfilterclass

	namespace cfiltermassgreater {

		constexpr std::uint32_t m_fFilterMass{ 0x640 };

	} // namespace cfiltermassgreater

	namespace cfiltermodel {

		constexpr std::uint32_t m_iFilterModel{ 0x640 };

	} // namespace cfiltermodel

	namespace cfiltermultiple {

		constexpr std::uint32_t m_nFilterType{ 0x640 };
		constexpr std::uint32_t m_iFilterName{ 0x648 };
		constexpr std::uint32_t m_hFilter{ 0x698 };

	} // namespace cfiltermultiple

	namespace cfiltername {

		constexpr std::uint32_t m_iFilterName{ 0x640 };

	} // namespace cfiltername

	namespace cfilterproximity {

		constexpr std::uint32_t m_flRadius{ 0x640 };

	} // namespace cfilterproximity

	namespace cfilterteam {

		constexpr std::uint32_t m_iFilterTeam{ 0x640 };

	} // namespace cfilterteam

	namespace cfiringmodefloat {

		constexpr std::uint32_t m_flValues{ 0x0 };

	} // namespace cfiringmodefloat

	namespace cfiringmodeint {

		constexpr std::uint32_t m_nValues{ 0x0 };

	} // namespace cfiringmodeint

	namespace cflashlighteffect {

		constexpr std::uint32_t m_bIsOn{ 0x10 };
		constexpr std::uint32_t m_bMuzzleFlashEnabled{ 0x20 };
		constexpr std::uint32_t m_flMuzzleFlashBrightness{ 0x24 };
		constexpr std::uint32_t m_quatMuzzleFlashOrientation{ 0x30 };
		constexpr std::uint32_t m_vecMuzzleFlashOrigin{ 0x40 };
		constexpr std::uint32_t m_flFov{ 0x4C };
		constexpr std::uint32_t m_flFarZ{ 0x50 };
		constexpr std::uint32_t m_flLinearAtten{ 0x54 };
		constexpr std::uint32_t m_bCastsShadows{ 0x58 };
		constexpr std::uint32_t m_flCurrentPullBackDist{ 0x5C };
		constexpr std::uint32_t m_FlashlightTexture{ 0x60 };
		constexpr std::uint32_t m_MuzzleFlashTexture{ 0x68 };
		constexpr std::uint32_t m_textureName{ 0x70 };

	} // namespace cflashlighteffect

	namespace cfuncwater {

		constexpr std::uint32_t m_BuoyancyHelper{ 0xE88 };

	} // namespace cfuncwater

	namespace cfuseprogram {

		constexpr std::uint32_t m_programBuffer{ 0x0 };
		constexpr std::uint32_t m_variablesRead{ 0x18 };
		constexpr std::uint32_t m_variablesWritten{ 0x30 };
		constexpr std::uint32_t m_nMaxTempVarsUsed{ 0x48 };

	} // namespace cfuseprogram

	namespace cfusesymboltable {

		constexpr std::uint32_t m_constants{ 0x0 };
		constexpr std::uint32_t m_variables{ 0x18 };
		constexpr std::uint32_t m_functions{ 0x30 };
		constexpr std::uint32_t m_constantMap{ 0x48 };
		constexpr std::uint32_t m_variableMap{ 0x68 };
		constexpr std::uint32_t m_functionMap{ 0x88 };

	} // namespace cfusesymboltable

	namespace cgamescenenode {

		constexpr std::uint32_t m_bBoneMergeFlex{ 0x0 };
		constexpr std::uint32_t m_bDirtyBoneMergeBoneToRoot{ 0x0 };
		constexpr std::uint32_t m_bDirtyBoneMergeInfo{ 0x0 };
		constexpr std::uint32_t m_bDirtyHierarchy{ 0x0 };
		constexpr std::uint32_t m_bNetworkedAnglesChanged{ 0x0 };
		constexpr std::uint32_t m_bNetworkedPositionChanged{ 0x0 };
		constexpr std::uint32_t m_bNetworkedScaleChanged{ 0x0 };
		constexpr std::uint32_t m_bWillBeCallingPostDataUpdate{ 0x0 };
		constexpr std::uint32_t m_nLatchAbsOrigin{ 0x0 };
		constexpr std::uint32_t m_nodeToWorld{ 0x10 };
		constexpr std::uint32_t m_pOwner{ 0x30 };
		constexpr std::uint32_t m_pParent{ 0x38 };
		constexpr std::uint32_t m_pChild{ 0x40 };
		constexpr std::uint32_t m_pNextSibling{ 0x48 };
		constexpr std::uint32_t m_hParent{ 0x78 };
		constexpr std::uint32_t m_vecOrigin{ 0x88 };
		constexpr std::uint32_t m_angRotation{ 0xC0 };
		constexpr std::uint32_t m_flScale{ 0xCC };
		constexpr std::uint32_t m_vecAbsOrigin{ 0xD0 };
		constexpr std::uint32_t m_angAbsRotation{ 0xDC };
		constexpr std::uint32_t m_flAbsScale{ 0xE8 };
		constexpr std::uint32_t m_vecWrappedLocalOrigin{ 0xEC };
		constexpr std::uint32_t m_angWrappedLocalRotation{ 0xF8 };
		constexpr std::uint32_t m_flWrappedScale{ 0x104 };
		constexpr std::uint32_t m_nParentAttachmentOrBone{ 0x108 };
		constexpr std::uint32_t m_bDebugAbsOriginChanges{ 0x10A };
		constexpr std::uint32_t m_bDormant{ 0x10B };
		constexpr std::uint32_t m_bForceParentToBeNetworked{ 0x10C };
		constexpr std::uint32_t m_nHierarchicalDepth{ 0x10F };
		constexpr std::uint32_t m_nHierarchyType{ 0x110 };
		constexpr std::uint32_t m_nDoNotSetAnimTimeInInvalidatePhysicsCount{ 0x111 };
		constexpr std::uint32_t m_name{ 0x114 };
		constexpr std::uint32_t m_hierarchyAttachName{ 0x128 };
		constexpr std::uint32_t m_flZOffset{ 0x12C };
		constexpr std::uint32_t m_flClientLocalScale{ 0x130 };
		constexpr std::uint32_t m_vRenderOrigin{ 0x134 };

	} // namespace cgamescenenode

	namespace cgamescenenodehandle {

		constexpr std::uint32_t m_hOwner{ 0x8 };
		constexpr std::uint32_t m_name{ 0xC };

	} // namespace cgamescenenodehandle

	namespace cgloballightbase {

		constexpr std::uint32_t m_bSpotLight{ 0x10 };
		constexpr std::uint32_t m_SpotLightOrigin{ 0x14 };
		constexpr std::uint32_t m_SpotLightAngles{ 0x20 };
		constexpr std::uint32_t m_ShadowDirection{ 0x2C };
		constexpr std::uint32_t m_AmbientDirection{ 0x38 };
		constexpr std::uint32_t m_SpecularDirection{ 0x44 };
		constexpr std::uint32_t m_InspectorSpecularDirection{ 0x50 };
		constexpr std::uint32_t m_flSpecularPower{ 0x5C };
		constexpr std::uint32_t m_flSpecularIndependence{ 0x60 };
		constexpr std::uint32_t m_SpecularColor{ 0x64 };
		constexpr std::uint32_t m_bStartDisabled{ 0x68 };
		constexpr std::uint32_t m_bEnabled{ 0x69 };
		constexpr std::uint32_t m_LightColor{ 0x6A };
		constexpr std::uint32_t m_AmbientColor1{ 0x6E };
		constexpr std::uint32_t m_AmbientColor2{ 0x72 };
		constexpr std::uint32_t m_AmbientColor3{ 0x76 };
		constexpr std::uint32_t m_flSunDistance{ 0x7C };
		constexpr std::uint32_t m_flFOV{ 0x80 };
		constexpr std::uint32_t m_flNearZ{ 0x84 };
		constexpr std::uint32_t m_flFarZ{ 0x88 };
		constexpr std::uint32_t m_bEnableShadows{ 0x8C };
		constexpr std::uint32_t m_bOldEnableShadows{ 0x8D };
		constexpr std::uint32_t m_bBackgroundClearNotRequired{ 0x8E };
		constexpr std::uint32_t m_flCloudScale{ 0x90 };
		constexpr std::uint32_t m_flCloud1Speed{ 0x94 };
		constexpr std::uint32_t m_flCloud1Direction{ 0x98 };
		constexpr std::uint32_t m_flCloud2Speed{ 0x9C };
		constexpr std::uint32_t m_flCloud2Direction{ 0xA0 };
		constexpr std::uint32_t m_flAmbientScale1{ 0xB0 };
		constexpr std::uint32_t m_flAmbientScale2{ 0xB4 };
		constexpr std::uint32_t m_flGroundScale{ 0xB8 };
		constexpr std::uint32_t m_flLightScale{ 0xBC };
		constexpr std::uint32_t m_flFoWDarkness{ 0xC0 };
		constexpr std::uint32_t m_bEnableSeparateSkyboxFog{ 0xC4 };
		constexpr std::uint32_t m_vFowColor{ 0xC8 };
		constexpr std::uint32_t m_ViewOrigin{ 0xD4 };
		constexpr std::uint32_t m_ViewAngles{ 0xE0 };
		constexpr std::uint32_t m_flViewFoV{ 0xEC };
		constexpr std::uint32_t m_WorldPoints{ 0xF0 };
		constexpr std::uint32_t m_vFogOffsetLayer0{ 0x4A8 };
		constexpr std::uint32_t m_vFogOffsetLayer1{ 0x4B0 };
		constexpr std::uint32_t m_hEnvWind{ 0x4B8 };
		constexpr std::uint32_t m_hEnvSky{ 0x4BC };

	} // namespace cgloballightbase

	namespace cglowproperty {

		constexpr std::uint32_t m_fGlowColor{ 0x8 };
		constexpr std::uint32_t m_iGlowType{ 0x30 };
		constexpr std::uint32_t m_iGlowTeam{ 0x34 };
		constexpr std::uint32_t m_nGlowRange{ 0x38 };
		constexpr std::uint32_t m_nGlowRangeMin{ 0x3C };
		constexpr std::uint32_t m_glowColorOverride{ 0x40 };
		constexpr std::uint32_t m_bFlashing{ 0x44 };
		constexpr std::uint32_t m_flGlowTime{ 0x48 };
		constexpr std::uint32_t m_flGlowStartTime{ 0x4C };
		constexpr std::uint32_t m_bEligibleForScreenHighlight{ 0x50 };
		constexpr std::uint32_t m_bGlowing{ 0x51 };

	} // namespace cglowproperty

	namespace cgrenadetracer {

		constexpr std::uint32_t m_flTracerDuration{ 0xEA0 };
		constexpr std::uint32_t m_nType{ 0xEA4 };

	} // namespace cgrenadetracer

	namespace chitboxcomponent {

		constexpr std::uint32_t m_flBoundsExpandRadius{ 0x14 };

	} // namespace chitboxcomponent

	namespace cinbuttonstate {

		constexpr std::uint32_t m_pButtonStates{ 0x8 };

	} // namespace cinbuttonstate

	namespace cinfodynamicshadowhint {

		constexpr std::uint32_t m_bDisabled{ 0x608 };
		constexpr std::uint32_t m_flRange{ 0x60C };
		constexpr std::uint32_t m_nImportance{ 0x610 };
		constexpr std::uint32_t m_nLightChoice{ 0x614 };
		constexpr std::uint32_t m_hLight{ 0x618 };

	} // namespace cinfodynamicshadowhint

	namespace cinfodynamicshadowhintbox {

		constexpr std::uint32_t m_vBoxMins{ 0x620 };
		constexpr std::uint32_t m_vBoxMaxs{ 0x62C };

	} // namespace cinfodynamicshadowhintbox

	namespace cinfofan {

		constexpr std::uint32_t m_fFanForceMaxRadius{ 0x648 };
		constexpr std::uint32_t m_fFanForceMinRadius{ 0x64C };
		constexpr std::uint32_t m_flCurveDistRange{ 0x650 };
		constexpr std::uint32_t m_FanForceCurveString{ 0x658 };

	} // namespace cinfofan

	namespace cinfointeraction {

		constexpr std::uint32_t m_strSlotEntityName{ 0x608 };
		constexpr std::uint32_t m_strInteractVData{ 0x648 };
		constexpr std::uint32_t m_flInteractRadius{ 0x650 };

	} // namespace cinfointeraction

	namespace cinfooffscreenpanoramatexture {

		constexpr std::uint32_t m_bDisabled{ 0x608 };
		constexpr std::uint32_t m_nResolutionX{ 0x60C };
		constexpr std::uint32_t m_nResolutionY{ 0x610 };
		constexpr std::uint32_t m_szPanelType{ 0x618 };
		constexpr std::uint32_t m_szLayoutFileName{ 0x620 };
		constexpr std::uint32_t m_RenderAttrName{ 0x628 };
		constexpr std::uint32_t m_TargetEntities{ 0x630 };
		constexpr std::uint32_t m_nTargetChangeCount{ 0x648 };
		constexpr std::uint32_t m_vecCSSClasses{ 0x650 };
		constexpr std::uint32_t m_szTargetsName{ 0x668 };
		constexpr std::uint32_t m_AdditionalTargetEntities{ 0x670 };
		constexpr std::uint32_t m_bCheckCSSClasses{ 0x7E8 };

	} // namespace cinfooffscreenpanoramatexture

	namespace cinfoworldlayer {

		constexpr std::uint32_t m_pOutputOnEntitiesSpawned{ 0x608 };
		constexpr std::uint32_t m_worldName{ 0x620 };
		constexpr std::uint32_t m_layerName{ 0x628 };
		constexpr std::uint32_t m_bWorldLayerVisible{ 0x630 };
		constexpr std::uint32_t m_bEntitiesSpawned{ 0x631 };
		constexpr std::uint32_t m_bCreateAsChildSpawnGroup{ 0x632 };
		constexpr std::uint32_t m_hLayerSpawnGroup{ 0x634 };
		constexpr std::uint32_t m_bWorldLayerActuallyVisible{ 0x638 };

	} // namespace cinfoworldlayer

	namespace cinterpolatedvalue {

		constexpr std::uint32_t m_flStartTime{ 0x0 };
		constexpr std::uint32_t m_flEndTime{ 0x4 };
		constexpr std::uint32_t m_flStartValue{ 0x8 };
		constexpr std::uint32_t m_flEndValue{ 0xC };
		constexpr std::uint32_t m_nInterpType{ 0x10 };

	} // namespace cinterpolatedvalue

	namespace cinventoryimagedata {

		constexpr std::uint32_t m_nNodeType{ 0x0 };
		constexpr std::uint32_t name{ 0x8 };
		constexpr std::uint32_t inventory_image_data{ 0x10 };

	} // namespace cinventoryimagedata

	namespace clightcomponent {

		constexpr std::uint32_t __m_pChainEntity{ 0x38 };
		constexpr std::uint32_t m_Color{ 0x75 };
		constexpr std::uint32_t m_SecondaryColor{ 0x79 };
		constexpr std::uint32_t m_flBrightness{ 0x80 };
		constexpr std::uint32_t m_flBrightnessScale{ 0x84 };
		constexpr std::uint32_t m_flBrightnessMult{ 0x88 };
		constexpr std::uint32_t m_flRange{ 0x8C };
		constexpr std::uint32_t m_flFalloff{ 0x90 };
		constexpr std::uint32_t m_flAttenuation0{ 0x94 };
		constexpr std::uint32_t m_flAttenuation1{ 0x98 };
		constexpr std::uint32_t m_flAttenuation2{ 0x9C };
		constexpr std::uint32_t m_flTheta{ 0xA0 };
		constexpr std::uint32_t m_flPhi{ 0xA4 };
		constexpr std::uint32_t m_hLightCookie{ 0xA8 };
		constexpr std::uint32_t m_nCascades{ 0xB0 };
		constexpr std::uint32_t m_nCastShadows{ 0xB4 };
		constexpr std::uint32_t m_nShadowWidth{ 0xB8 };
		constexpr std::uint32_t m_nShadowHeight{ 0xBC };
		constexpr std::uint32_t m_bRenderDiffuse{ 0xC0 };
		constexpr std::uint32_t m_nRenderSpecular{ 0xC4 };
		constexpr std::uint32_t m_bRenderTransmissive{ 0xC8 };
		constexpr std::uint32_t m_flOrthoLightWidth{ 0xCC };
		constexpr std::uint32_t m_flOrthoLightHeight{ 0xD0 };
		constexpr std::uint32_t m_nStyle{ 0xD4 };
		constexpr std::uint32_t m_Pattern{ 0xD8 };
		constexpr std::uint32_t m_nCascadeRenderStaticObjects{ 0xE0 };
		constexpr std::uint32_t m_flShadowCascadeCrossFade{ 0xE4 };
		constexpr std::uint32_t m_flShadowCascadeDistanceFade{ 0xE8 };
		constexpr std::uint32_t m_flShadowCascadeDistance0{ 0xEC };
		constexpr std::uint32_t m_flShadowCascadeDistance1{ 0xF0 };
		constexpr std::uint32_t m_flShadowCascadeDistance2{ 0xF4 };
		constexpr std::uint32_t m_flShadowCascadeDistance3{ 0xF8 };
		constexpr std::uint32_t m_nShadowCascadeResolution0{ 0xFC };
		constexpr std::uint32_t m_nShadowCascadeResolution1{ 0x100 };
		constexpr std::uint32_t m_nShadowCascadeResolution2{ 0x104 };
		constexpr std::uint32_t m_nShadowCascadeResolution3{ 0x108 };
		constexpr std::uint32_t m_bUsesBakedShadowing{ 0x10C };
		constexpr std::uint32_t m_nShadowPriority{ 0x110 };
		constexpr std::uint32_t m_nBakedShadowIndex{ 0x114 };
		constexpr std::uint32_t m_nLightPathUniqueId{ 0x118 };
		constexpr std::uint32_t m_nLightMapUniqueId{ 0x11C };
		constexpr std::uint32_t m_bRenderToCubemaps{ 0x120 };
		constexpr std::uint32_t m_bAllowSSTGeneration{ 0x121 };
		constexpr std::uint32_t m_nDirectLight{ 0x124 };
		constexpr std::uint32_t m_nIndirectLight{ 0x128 };
		constexpr std::uint32_t m_bDynamicBounce{ 0x12C };
		constexpr std::uint32_t m_flFadeMinDist{ 0x130 };
		constexpr std::uint32_t m_flFadeMaxDist{ 0x134 };
		constexpr std::uint32_t m_flShadowFadeMinDist{ 0x138 };
		constexpr std::uint32_t m_flShadowFadeMaxDist{ 0x13C };
		constexpr std::uint32_t m_bEnabled{ 0x140 };
		constexpr std::uint32_t m_bFlicker{ 0x141 };
		constexpr std::uint32_t m_bPrecomputedFieldsValid{ 0x142 };
		constexpr std::uint32_t m_vPrecomputedBoundsMins{ 0x144 };
		constexpr std::uint32_t m_vPrecomputedBoundsMaxs{ 0x150 };
		constexpr std::uint32_t m_vPrecomputedOBBOrigin{ 0x15C };
		constexpr std::uint32_t m_vPrecomputedOBBAngles{ 0x168 };
		constexpr std::uint32_t m_vPrecomputedOBBExtent{ 0x174 };
		constexpr std::uint32_t m_flPrecomputedMaxRange{ 0x180 };
		constexpr std::uint32_t m_nFogLightingMode{ 0x184 };
		constexpr std::uint32_t m_flFogContributionStength{ 0x188 };
		constexpr std::uint32_t m_flNearClipPlane{ 0x18C };
		constexpr std::uint32_t m_SkyColor{ 0x190 };
		constexpr std::uint32_t m_flSkyIntensity{ 0x194 };
		constexpr std::uint32_t m_SkyAmbientBounce{ 0x198 };
		constexpr std::uint32_t m_bUseSecondaryColor{ 0x19C };
		constexpr std::uint32_t m_bMixedShadows{ 0x19D };
		constexpr std::uint32_t m_flLightStyleStartTime{ 0x1A0 };
		constexpr std::uint32_t m_flCapsuleLength{ 0x1A4 };
		constexpr std::uint32_t m_flMinRoughness{ 0x1A8 };

	} // namespace clightcomponent

	namespace clogicrelay {

		constexpr std::uint32_t m_bDisabled{ 0x608 };
		constexpr std::uint32_t m_bWaitForRefire{ 0x609 };
		constexpr std::uint32_t m_bTriggerOnce{ 0x60A };
		constexpr std::uint32_t m_bFastRetrigger{ 0x60B };
		constexpr std::uint32_t m_bPassthoughCaller{ 0x60C };

	} // namespace clogicrelay

	namespace cmapinfo {

		constexpr std::uint32_t m_iBuyingStatus{ 0x608 };
		constexpr std::uint32_t m_flBombRadius{ 0x60C };
		constexpr std::uint32_t m_iPetPopulation{ 0x610 };
		constexpr std::uint32_t m_bUseNormalSpawnsForDM{ 0x614 };
		constexpr std::uint32_t m_bDisableAutoGeneratedDMSpawns{ 0x615 };
		constexpr std::uint32_t m_flBotMaxVisionDistance{ 0x618 };
		constexpr std::uint32_t m_iHostageCount{ 0x61C };
		constexpr std::uint32_t m_bFadePlayerVisibilityFarZ{ 0x620 };
		constexpr std::uint32_t m_bRainTraceToSkyEnabled{ 0x621 };
		constexpr std::uint32_t m_flEnvRainStrength{ 0x624 };
		constexpr std::uint32_t m_flEnvPuddleRippleStrength{ 0x628 };
		constexpr std::uint32_t m_flEnvPuddleRippleDirection{ 0x62C };
		constexpr std::uint32_t m_flEnvWetnessCoverage{ 0x630 };
		constexpr std::uint32_t m_flEnvWetnessDryingAmount{ 0x634 };

	} // namespace cmapinfo

	namespace cmodelstate {

		constexpr std::uint32_t m_hModel{ 0xA0 };
		constexpr std::uint32_t m_ModelName{ 0xA8 };
		constexpr std::uint32_t m_bClientClothCreationSuppressed{ 0x179 };
		constexpr std::uint32_t m_MeshGroupMask{ 0x220 };
		constexpr std::uint32_t m_nBodyGroupChoices{ 0x270 };
		constexpr std::uint32_t m_nIdealMotionType{ 0x2BA };
		constexpr std::uint32_t m_nForceLOD{ 0x2BB };
		constexpr std::uint32_t m_nClothUpdateFlags{ 0x2BC };

	} // namespace cmodelstate

	namespace cnetworkedsequenceoperation {

		constexpr std::uint32_t m_hSequence{ 0x8 };
		constexpr std::uint32_t m_flPrevCycle{ 0xC };
		constexpr std::uint32_t m_flCycle{ 0x10 };
		constexpr std::uint32_t m_flWeight{ 0x14 };
		constexpr std::uint32_t m_bSequenceChangeNetworked{ 0x1C };
		constexpr std::uint32_t m_bDiscontinuity{ 0x1D };
		constexpr std::uint32_t m_flPrevCycleFromDiscontinuity{ 0x20 };
		constexpr std::uint32_t m_flPrevCycleForAnimEventDetection{ 0x24 };

	} // namespace cnetworkedsequenceoperation

	namespace cnetworkorigincellcoordquantizedvector {

		constexpr std::uint32_t m_cellX{ 0x10 };
		constexpr std::uint32_t m_cellY{ 0x12 };
		constexpr std::uint32_t m_cellZ{ 0x14 };
		constexpr std::uint32_t m_nOutsideWorld{ 0x16 };
		constexpr std::uint32_t m_vecX{ 0x18 };
		constexpr std::uint32_t m_vecY{ 0x20 };
		constexpr std::uint32_t m_vecZ{ 0x28 };

	} // namespace cnetworkorigincellcoordquantizedvector

	namespace cnetworkoriginquantizedvector {

		constexpr std::uint32_t m_vecX{ 0x10 };
		constexpr std::uint32_t m_vecY{ 0x18 };
		constexpr std::uint32_t m_vecZ{ 0x20 };

	} // namespace cnetworkoriginquantizedvector

	namespace cnetworktransmitcomponent {

		constexpr std::uint32_t m_nTransmitStateOwnedCounter{ 0x184 };

	} // namespace cnetworktransmitcomponent

	namespace cnetworkvarchainer {

		constexpr std::uint32_t m_PathIndex{ 0x20 };

	} // namespace cnetworkvarchainer

	namespace cnetworkvelocityvector {

		constexpr std::uint32_t m_vecX{ 0x10 };
		constexpr std::uint32_t m_vecY{ 0x18 };
		constexpr std::uint32_t m_vecZ{ 0x20 };

	} // namespace cnetworkvelocityvector

	namespace cnetworkviewoffsetvector {

		constexpr std::uint32_t m_vecX{ 0x10 };
		constexpr std::uint32_t m_vecY{ 0x18 };
		constexpr std::uint32_t m_vecZ{ 0x20 };

	} // namespace cnetworkviewoffsetvector

	namespace cnewparticleeffect {

		constexpr std::uint32_t m_bAllocated{ 0x0 };
		constexpr std::uint32_t m_bAutoUpdateBBox{ 0x0 };
		constexpr std::uint32_t m_bCanFreeze{ 0x0 };
		constexpr std::uint32_t m_bDontRemove{ 0x0 };
		constexpr std::uint32_t m_bForceNoDraw{ 0x0 };
		constexpr std::uint32_t m_bFreezeTargetState{ 0x0 };
		constexpr std::uint32_t m_bFreezeTransitionActive{ 0x0 };
		constexpr std::uint32_t m_bIsAsyncCreate{ 0x0 };
		constexpr std::uint32_t m_bIsFirstFrame{ 0x0 };
		constexpr std::uint32_t m_bNeedsBBoxUpdate{ 0x0 };
		constexpr std::uint32_t m_bRemove{ 0x0 };
		constexpr std::uint32_t m_bShouldCheckFoW{ 0x0 };
		constexpr std::uint32_t m_bShouldPerformCullCheck{ 0x0 };
		constexpr std::uint32_t m_bShouldSave{ 0x0 };
		constexpr std::uint32_t m_bShouldSimulateDuringGamePaused{ 0x0 };
		constexpr std::uint32_t m_bSimulate{ 0x0 };
		constexpr std::uint32_t m_bSuppressScreenSpaceEffect{ 0x0 };
		constexpr std::uint32_t m_pNext{ 0x10 };
		constexpr std::uint32_t m_pPrev{ 0x18 };
		constexpr std::uint32_t m_pParticles{ 0x20 };
		constexpr std::uint32_t m_pDebugName{ 0x28 };
		constexpr std::uint32_t m_vSortOrigin{ 0x40 };
		constexpr std::uint32_t m_flScale{ 0x4C };
		constexpr std::uint32_t m_hOwner{ 0x50 };
		constexpr std::uint32_t m_pOwningParticleProperty{ 0x58 };
		constexpr std::uint32_t m_flFreezeTransitionStart{ 0x70 };
		constexpr std::uint32_t m_flFreezeTransitionDuration{ 0x74 };
		constexpr std::uint32_t m_flFreezeTransitionOverride{ 0x78 };
		constexpr std::uint32_t m_LastMin{ 0x7C };
		constexpr std::uint32_t m_LastMax{ 0x88 };
		constexpr std::uint32_t m_nSplitScreenUser{ 0x94 };
		constexpr std::uint32_t m_vecAggregationCenter{ 0x98 };
		constexpr std::uint32_t m_RefCount{ 0xD0 };

	} // namespace cnewparticleeffect

	namespace cnmaimcsnode__cdefinition {

		constexpr std::uint32_t m_nVerticalAngleNodeIdx{ 0x18 };
		constexpr std::uint32_t m_nHorizontalAngleNodeIdx{ 0x1A };
		constexpr std::uint32_t m_nWeaponCategoryNodeIdx{ 0x1C };
		constexpr std::uint32_t m_nWeaponTypeNodeIdx{ 0x1E };
		constexpr std::uint32_t m_nIsWeaponActionActiveNodeIdx{ 0x20 };
		constexpr std::uint32_t m_nWeaponDropNodeIdx{ 0x22 };
		constexpr std::uint32_t m_nEnabledNodeIdx{ 0x24 };
		constexpr std::uint32_t m_flBlendTimeSeconds{ 0x28 };
		constexpr std::uint32_t m_flReduceRangeTimeSeconds{ 0x2C };

	} // namespace cnmaimcsnode__cdefinition

	namespace cnmandnode__cdefinition {

		constexpr std::uint32_t m_conditionNodeIndices{ 0x10 };

	} // namespace cnmandnode__cdefinition

	namespace cnmanimationposenode__cdefinition {

		constexpr std::uint32_t m_nPoseTimeValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nDataSlotIdx{ 0x12 };
		constexpr std::uint32_t m_inputTimeRemapRange{ 0x14 };
		constexpr std::uint32_t m_flUserSpecifiedTime{ 0x1C };
		constexpr std::uint32_t m_bUseFramesAsInput{ 0x20 };

	} // namespace cnmanimationposenode__cdefinition

	namespace cnmbitflags {

		constexpr std::uint32_t m_flags{ 0x0 };

	} // namespace cnmbitflags

	namespace cnmblend1dnode__cdefinition {

		constexpr std::uint32_t m_parameterization{ 0x40 };

	} // namespace cnmblend1dnode__cdefinition

	namespace cnmblend2dnode__cdefinition {

		constexpr std::uint32_t m_sourceNodeIndices{ 0x10 };
		constexpr std::uint32_t m_nInputParameterNodeIdx0{ 0x38 };
		constexpr std::uint32_t m_nInputParameterNodeIdx1{ 0x3A };
		constexpr std::uint32_t m_values{ 0x40 };
		constexpr std::uint32_t m_indices{ 0xA8 };
		constexpr std::uint32_t m_hullIndices{ 0xE0 };
		constexpr std::uint32_t m_bAllowLooping{ 0x108 };

	} // namespace cnmblend2dnode__cdefinition

	namespace cnmbodygroupevent {

		constexpr std::uint32_t m_groupName{ 0x20 };
		constexpr std::uint32_t m_nGroupValue{ 0x28 };

	} // namespace cnmbodygroupevent

	namespace cnmbonemaskblendnode__cdefinition {

		constexpr std::uint32_t m_nSourceMaskNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nTargetMaskNodeIdx{ 0x12 };
		constexpr std::uint32_t m_nBlendWeightValueNodeIdx{ 0x14 };

	} // namespace cnmbonemaskblendnode__cdefinition

	namespace cnmbonemasknode__cdefinition {

		constexpr std::uint32_t m_boneMaskID{ 0x10 };

	} // namespace cnmbonemasknode__cdefinition

	namespace cnmbonemaskselectornode__cdefinition {

		constexpr std::uint32_t m_defaultMaskNodeIdx{ 0x10 };
		constexpr std::uint32_t m_parameterValueNodeIdx{ 0x12 };
		constexpr std::uint32_t m_bSwitchDynamically{ 0x14 };
		constexpr std::uint32_t m_maskNodeIndices{ 0x18 };
		constexpr std::uint32_t m_parameterValues{ 0x40 };
		constexpr std::uint32_t m_flBlendTimeSeconds{ 0x90 };

	} // namespace cnmbonemaskselectornode__cdefinition

	namespace cnmbonemaskswitchnode__cdefinition {

		constexpr std::uint32_t m_nSwitchValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nTrueValueNodeIdx{ 0x12 };
		constexpr std::uint32_t m_nFalseValueNodeIdx{ 0x14 };
		constexpr std::uint32_t m_flBlendTimeSeconds{ 0x18 };
		constexpr std::uint32_t m_bSwitchDynamically{ 0x1C };

	} // namespace cnmbonemaskswitchnode__cdefinition

	namespace cnmboneweightlist {

		constexpr std::uint32_t m_skeletonName{ 0x0 };
		constexpr std::uint32_t m_boneIDs{ 0xE0 };
		constexpr std::uint32_t m_weights{ 0xF8 };

	} // namespace cnmboneweightlist

	namespace cnmcachedboolnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_mode{ 0x14 };

	} // namespace cnmcachedboolnode__cdefinition

	namespace cnmcachedfloatnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_mode{ 0x14 };

	} // namespace cnmcachedfloatnode__cdefinition

	namespace cnmcachedidnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_mode{ 0x14 };

	} // namespace cnmcachedidnode__cdefinition

	namespace cnmcachedtargetnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_mode{ 0x14 };

	} // namespace cnmcachedtargetnode__cdefinition

	namespace cnmcachedvectornode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_mode{ 0x14 };

	} // namespace cnmcachedvectornode__cdefinition

	namespace cnmchainlookatnode__cdefinition {

		constexpr std::uint32_t m_chainEndBoneID{ 0x18 };
		constexpr std::uint32_t m_nLookatTargetNodeIdx{ 0x20 };
		constexpr std::uint32_t m_nEnabledNodeIdx{ 0x22 };
		constexpr std::uint32_t m_flBlendTimeSeconds{ 0x24 };
		constexpr std::uint32_t m_nChainLength{ 0x28 };
		constexpr std::uint32_t m_bIsTargetInWorldSpace{ 0x29 };
		constexpr std::uint32_t m_chainForwardDir{ 0x2C };

	} // namespace cnmchainlookatnode__cdefinition

	namespace cnmchainlookattask {

		constexpr std::uint32_t m_nChainEndBoneIdx{ 0x58 };
		constexpr std::uint32_t m_nNumBonesInChain{ 0x5C };
		constexpr std::uint32_t m_chainForwardDir{ 0x60 };
		constexpr std::uint32_t m_flBlendWeight{ 0x6C };
		constexpr std::uint32_t m_flHorizontalAngleLimitDegrees{ 0x70 };
		constexpr std::uint32_t m_flVerticalAngleLimitDegrees{ 0x74 };
		constexpr std::uint32_t m_lookatTarget{ 0x78 };
		constexpr std::uint32_t m_bIsTargetInWorldSpace{ 0x84 };
		constexpr std::uint32_t m_bIsRunningFromDeserializedData{ 0x85 };
		constexpr std::uint32_t m_flHorizontalAngleDegrees{ 0x88 };
		constexpr std::uint32_t m_flVerticalAngleDegrees{ 0x8C };

	} // namespace cnmchainlookattask

	namespace cnmchainsolvertask {

		constexpr std::uint32_t m_nEffectorBoneIdx{ 0x58 };
		constexpr std::uint32_t m_nEffectorTargetBoneIdx{ 0x5C };
		constexpr std::uint32_t m_targetTransform{ 0x60 };
		constexpr std::uint32_t m_nNumBonesInChain{ 0x80 };
		constexpr std::uint32_t m_effectorTarget{ 0x90 };
		constexpr std::uint32_t m_blendMode{ 0xC0 };
		constexpr std::uint32_t m_flBlendWeight{ 0xC4 };
		constexpr std::uint32_t m_bIsTargetInWorldSpace{ 0xC8 };
		constexpr std::uint32_t m_bIsRunningFromDeserializedData{ 0xC9 };
		constexpr std::uint32_t m_debugEffectorBoneID{ 0xD0 };
		constexpr std::uint32_t m_chainStartTransformMS{ 0xE0 };
		constexpr std::uint32_t m_debugRequestedTargetTransformMS{ 0x100 };
		constexpr std::uint32_t m_debugTotalChainLength{ 0x120 };

	} // namespace cnmchainsolvertask

	namespace cnmclip {

		constexpr std::uint32_t m_skeleton{ 0x0 };
		constexpr std::uint32_t m_nNumFrames{ 0x8 };
		constexpr std::uint32_t m_flDuration{ 0xC };
		constexpr std::uint32_t m_compressedPoseData{ 0x10 };
		constexpr std::uint32_t m_trackCompressionSettings{ 0x20 };
		constexpr std::uint32_t m_compressedPoseOffsets{ 0x38 };
		constexpr std::uint32_t m_floatCurveIDs{ 0x50 };
		constexpr std::uint32_t m_floatCurveDefs{ 0x68 };
		constexpr std::uint32_t m_compressedFloatCurveData{ 0x80 };
		constexpr std::uint32_t m_compressedFloatCurveOffsets{ 0x98 };
		constexpr std::uint32_t m_secondaryAnimations{ 0xD8 };
		constexpr std::uint32_t m_syncTrack{ 0xF8 };
		constexpr std::uint32_t m_rootMotion{ 0x1B0 };
		constexpr std::uint32_t m_bIsAdditive{ 0x200 };
		constexpr std::uint32_t m_modelSpaceSamplingChain{ 0x208 };
		constexpr std::uint32_t m_modelSpaceBoneSamplingIndices{ 0x220 };

	} // namespace cnmclip

	namespace cnmclip__modelspacesamplingchainlink_t {

		constexpr std::uint32_t m_nBoneIdx{ 0x0 };
		constexpr std::uint32_t m_nParentBoneIdx{ 0x4 };
		constexpr std::uint32_t m_nParentChainLinkIdx{ 0x8 };

	} // namespace cnmclip__modelspacesamplingchainlink_t

	namespace cnmclipnode__cdefinition {

		constexpr std::uint32_t m_nPlayInReverseValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nResetTimeValueNodeIdx{ 0x12 };
		constexpr std::uint32_t m_bSampleRootMotion{ 0x14 };
		constexpr std::uint32_t m_bAllowLooping{ 0x15 };
		constexpr std::uint32_t m_nDataSlotIdx{ 0x16 };
		constexpr std::uint32_t m_graphEvents{ 0x18 };
		constexpr std::uint32_t m_flSpeedMultiplier{ 0x40 };
		constexpr std::uint32_t m_nStartSyncEventOffset{ 0x44 };

	} // namespace cnmclipnode__cdefinition

	namespace cnmclipselectornode__cdefinition {

		constexpr std::uint32_t m_optionNodeIndices{ 0x10 };
		constexpr std::uint32_t m_conditionNodeIndices{ 0x28 };

	} // namespace cnmclipselectornode__cdefinition

	namespace cnmconstboolnode__cdefinition {

		constexpr std::uint32_t m_bValue{ 0x10 };

	} // namespace cnmconstboolnode__cdefinition

	namespace cnmconstfloatnode__cdefinition {

		constexpr std::uint32_t m_flValue{ 0x10 };

	} // namespace cnmconstfloatnode__cdefinition

	namespace cnmconstidnode__cdefinition {

		constexpr std::uint32_t m_value{ 0x10 };

	} // namespace cnmconstidnode__cdefinition

	namespace cnmconsttargetnode__cdefinition {

		constexpr std::uint32_t m_value{ 0x10 };

	} // namespace cnmconsttargetnode__cdefinition

	namespace cnmconstvectornode__cdefinition {

		constexpr std::uint32_t m_value{ 0x10 };

	} // namespace cnmconstvectornode__cdefinition

	namespace cnmcurrentsynceventidnode__cdefinition {

		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x10 };

	} // namespace cnmcurrentsynceventidnode__cdefinition

	namespace cnmcurrentsynceventnode__cdefinition {

		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_infoType{ 0x12 };

	} // namespace cnmcurrentsynceventnode__cdefinition

	namespace cnmentityattributeeventbase {

		constexpr std::uint32_t m_attributeName{ 0x20 };

	} // namespace cnmentityattributeeventbase

	namespace cnmentityattributefloatevent {

		constexpr std::uint32_t m_FloatValue{ 0x38 };

	} // namespace cnmentityattributefloatevent

	namespace cnmentityattributeintevent {

		constexpr std::uint32_t m_nIntValue{ 0x38 };

	} // namespace cnmentityattributeintevent

	namespace cnmevent {

		constexpr std::uint32_t m_flStartTime{ 0x8 };
		constexpr std::uint32_t m_flDuration{ 0xC };
		constexpr std::uint32_t m_syncID{ 0x10 };
		constexpr std::uint32_t m_bClientOnly{ 0x18 };

	} // namespace cnmevent

	namespace cnmexternalposenode__cdefinition {

		constexpr std::uint32_t m_bShouldSampleRootMotion{ 0x10 };

	} // namespace cnmexternalposenode__cdefinition

	namespace cnmfixedweightbonemasknode__cdefinition {

		constexpr std::uint32_t m_flBoneWeight{ 0x10 };

	} // namespace cnmfixedweightbonemasknode__cdefinition

	namespace cnmfloatanglemathnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_operation{ 0x12 };

	} // namespace cnmfloatanglemathnode__cdefinition

	namespace cnmfloatclampnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_clampRange{ 0x14 };

	} // namespace cnmfloatclampnode__cdefinition

	namespace cnmfloatcomparisonnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nComparandValueNodeIdx{ 0x12 };
		constexpr std::uint32_t m_comparison{ 0x14 };
		constexpr std::uint32_t m_flEpsilon{ 0x18 };
		constexpr std::uint32_t m_flComparisonValue{ 0x1C };

	} // namespace cnmfloatcomparisonnode__cdefinition

	namespace cnmfloatcurveevent {

		constexpr std::uint32_t m_ID{ 0x20 };
		constexpr std::uint32_t m_curve{ 0x28 };

	} // namespace cnmfloatcurveevent

	namespace cnmfloatcurveeventnode__cdefinition {

		constexpr std::uint32_t m_eventID{ 0x10 };
		constexpr std::uint32_t m_nDefaultNodeIdx{ 0x18 };
		constexpr std::uint32_t m_flDefaultValue{ 0x1C };
		constexpr std::uint32_t m_eventConditionRules{ 0x20 };

	} // namespace cnmfloatcurveeventnode__cdefinition

	namespace cnmfloatcurvenode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_curve{ 0x18 };

	} // namespace cnmfloatcurvenode__cdefinition

	namespace cnmfloateasenode__cdefinition {

		constexpr std::uint32_t m_flEaseTime{ 0x10 };
		constexpr std::uint32_t m_flStartValue{ 0x14 };
		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x18 };
		constexpr std::uint32_t m_easingOp{ 0x1A };
		constexpr std::uint32_t m_bUseStartValue{ 0x1B };

	} // namespace cnmfloateasenode__cdefinition

	namespace cnmfloatmathnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdxA{ 0x10 };
		constexpr std::uint32_t m_nInputValueNodeIdxB{ 0x12 };
		constexpr std::uint32_t m_bReturnAbsoluteResult{ 0x14 };
		constexpr std::uint32_t m_bReturnNegatedResult{ 0x15 };
		constexpr std::uint32_t m_operator{ 0x16 };
		constexpr std::uint32_t m_flValueB{ 0x18 };

	} // namespace cnmfloatmathnode__cdefinition

	namespace cnmfloatrangecomparisonnode__cdefinition {

		constexpr std::uint32_t m_range{ 0x10 };
		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x18 };
		constexpr std::uint32_t m_bIsInclusiveCheck{ 0x1A };

	} // namespace cnmfloatrangecomparisonnode__cdefinition

	namespace cnmfloatremapnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_inputRange{ 0x14 };
		constexpr std::uint32_t m_outputRange{ 0x1C };

	} // namespace cnmfloatremapnode__cdefinition

	namespace cnmfloatremapnode__remaprange_t {

		constexpr std::uint32_t m_flBegin{ 0x0 };
		constexpr std::uint32_t m_flEnd{ 0x4 };

	} // namespace cnmfloatremapnode__remaprange_t

	namespace cnmfloatselectornode__cdefinition {

		constexpr std::uint32_t m_conditionNodeIndices{ 0x10 };
		constexpr std::uint32_t m_values{ 0x38 };
		constexpr std::uint32_t m_flDefaultValue{ 0x68 };
		constexpr std::uint32_t m_flEaseTime{ 0x6C };
		constexpr std::uint32_t m_easingOp{ 0x70 };

	} // namespace cnmfloatselectornode__cdefinition

	namespace cnmfloatswitchnode__cdefinition {

		constexpr std::uint32_t m_nSwitchValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nTrueValueNodeIdx{ 0x12 };
		constexpr std::uint32_t m_nFalseValueNodeIdx{ 0x14 };
		constexpr std::uint32_t m_flFalseValue{ 0x18 };
		constexpr std::uint32_t m_flTrueValue{ 0x1C };

	} // namespace cnmfloatswitchnode__cdefinition

	namespace cnmfollowbonenode__cdefinition {

		constexpr std::uint32_t m_bone{ 0x18 };
		constexpr std::uint32_t m_followTargetBone{ 0x20 };
		constexpr std::uint32_t m_nEnabledNodeIdx{ 0x28 };
		constexpr std::uint32_t m_mode{ 0x2A };

	} // namespace cnmfollowbonenode__cdefinition

	namespace cnmfootevent {

		constexpr std::uint32_t m_phase{ 0x20 };

	} // namespace cnmfootevent

	namespace cnmfooteventconditionnode__cdefinition {

		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_phaseCondition{ 0x12 };
		constexpr std::uint32_t m_eventConditionRules{ 0x14 };

	} // namespace cnmfooteventconditionnode__cdefinition

	namespace cnmfootstepeventidnode__cdefinition {

		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_eventConditionRules{ 0x14 };

	} // namespace cnmfootstepeventidnode__cdefinition

	namespace cnmfootstepeventpercentagethroughnode__cdefinition {

		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_phaseCondition{ 0x12 };
		constexpr std::uint32_t m_eventConditionRules{ 0x14 };

	} // namespace cnmfootstepeventpercentagethroughnode__cdefinition

	namespace cnmframesnapevent {

		constexpr std::uint32_t m_frameSnapMode{ 0x20 };

	} // namespace cnmframesnapevent

	namespace cnmgraphdefinition {

		constexpr std::uint32_t m_variationID{ 0x0 };
		constexpr std::uint32_t m_skeleton{ 0x8 };
		constexpr std::uint32_t m_pUserData{ 0x10 };
		constexpr std::uint32_t m_persistentNodeIndices{ 0x18 };
		constexpr std::uint32_t m_nRootNodeIdx{ 0x30 };
		constexpr std::uint32_t m_controlParameterIDs{ 0x38 };
		constexpr std::uint32_t m_virtualParameterIDs{ 0x50 };
		constexpr std::uint32_t m_virtualParameterNodeIndices{ 0x68 };
		constexpr std::uint32_t m_referencedGraphSlots{ 0x80 };
		constexpr std::uint32_t m_externalGraphSlots{ 0x98 };
		constexpr std::uint32_t m_externalPoseSlots{ 0xB0 };
		constexpr std::uint32_t m_nodePaths{ 0x138 };
		constexpr std::uint32_t m_resources{ 0x150 };

	} // namespace cnmgraphdefinition

	namespace cnmgraphdefinition__externalgraphslot_t {

		constexpr std::uint32_t m_nNodeIdx{ 0x0 };
		constexpr std::uint32_t m_slotID{ 0x8 };

	} // namespace cnmgraphdefinition__externalgraphslot_t

	namespace cnmgraphdefinition__externalposeslot_t {

		constexpr std::uint32_t m_nNodeIdx{ 0x0 };
		constexpr std::uint32_t m_slotID{ 0x8 };

	} // namespace cnmgraphdefinition__externalposeslot_t

	namespace cnmgraphdefinition__referencedgraphslot_t {

		constexpr std::uint32_t m_nNodeIdx{ 0x0 };
		constexpr std::uint32_t m_dataSlotIdx{ 0x2 };

	} // namespace cnmgraphdefinition__referencedgraphslot_t

	namespace cnmgrapheventconditionnode__cdefinition {

		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_eventConditionRules{ 0x14 };
		constexpr std::uint32_t m_conditions{ 0x18 };

	} // namespace cnmgrapheventconditionnode__cdefinition

	namespace cnmgrapheventconditionnode__condition_t {

		constexpr std::uint32_t m_eventID{ 0x0 };
		constexpr std::uint32_t m_eventTypeCondition{ 0x8 };

	} // namespace cnmgrapheventconditionnode__condition_t

	namespace cnmgraphnode__cdefinition {

		constexpr std::uint32_t m_nNodeIdx{ 0x8 };

	} // namespace cnmgraphnode__cdefinition

	namespace cnmidcomparisonnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_comparison{ 0x12 };
		constexpr std::uint32_t m_comparisionIDs{ 0x18 };

	} // namespace cnmidcomparisonnode__cdefinition

	namespace cnmidevent {

		constexpr std::uint32_t m_ID{ 0x20 };
		constexpr std::uint32_t m_secondaryID{ 0x28 };

	} // namespace cnmidevent

	namespace cnmideventconditionnode__cdefinition {

		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_eventConditionRules{ 0x14 };
		constexpr std::uint32_t m_eventIDs{ 0x18 };

	} // namespace cnmideventconditionnode__cdefinition

	namespace cnmideventnode__cdefinition {

		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_eventConditionRules{ 0x14 };
		constexpr std::uint32_t m_defaultValue{ 0x18 };

	} // namespace cnmideventnode__cdefinition

	namespace cnmideventpercentagethroughnode__cdefinition {

		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_eventConditionRules{ 0x14 };
		constexpr std::uint32_t m_eventID{ 0x18 };

	} // namespace cnmideventpercentagethroughnode__cdefinition

	namespace cnmidselectornode__cdefinition {

		constexpr std::uint32_t m_conditionNodeIndices{ 0x10 };
		constexpr std::uint32_t m_values{ 0x38 };
		constexpr std::uint32_t m_defaultValue{ 0x78 };

	} // namespace cnmidselectornode__cdefinition

	namespace cnmidswitchnode__cdefinition {

		constexpr std::uint32_t m_nSwitchValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nTrueValueNodeIdx{ 0x12 };
		constexpr std::uint32_t m_nFalseValueNodeIdx{ 0x14 };
		constexpr std::uint32_t m_falseValue{ 0x18 };
		constexpr std::uint32_t m_trueValue{ 0x20 };

	} // namespace cnmidswitchnode__cdefinition

	namespace cnmidtofloatnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_defaultValue{ 0x14 };
		constexpr std::uint32_t m_IDs{ 0x18 };
		constexpr std::uint32_t m_values{ 0x48 };

	} // namespace cnmidtofloatnode__cdefinition

	namespace cnmikbody {

		constexpr std::uint32_t m_flMass{ 0x0 };
		constexpr std::uint32_t m_vLocalMassCenter{ 0x4 };
		constexpr std::uint32_t m_vRadius{ 0x10 };
		constexpr std::uint32_t m_flResistance{ 0x1C };

	} // namespace cnmikbody

	namespace cnmikeffector {

		constexpr std::uint32_t m_nBodyIndex{ 0x0 };
		constexpr std::uint32_t m_bEnabled{ 0x4 };
		constexpr std::uint32_t m_vTargetPosition{ 0x8 };
		constexpr std::uint32_t m_qTargetOrientation{ 0x20 };
		constexpr std::uint32_t m_flWeight{ 0x30 };

	} // namespace cnmikeffector

	namespace cnmikjoint {

		constexpr std::uint32_t m_nParentIndex{ 0x0 };
		constexpr std::uint32_t m_nBodyIndex{ 0x4 };
		constexpr std::uint32_t m_xLocalFrame{ 0x10 };
		constexpr std::uint32_t m_flSwingLimit{ 0x30 };
		constexpr std::uint32_t m_flMinTwistLimit{ 0x34 };
		constexpr std::uint32_t m_flMaxTwistLimit{ 0x38 };
		constexpr std::uint32_t m_flWeight{ 0x3C };

	} // namespace cnmikjoint

	namespace cnmikrig {

		constexpr std::uint32_t m_skeleton{ 0x0 };
		constexpr std::uint32_t m_vecBodies{ 0x8 };
		constexpr std::uint32_t m_vecJoints{ 0x20 };

	} // namespace cnmikrig

	namespace cnmisexternalgraphslotfillednode__cdefinition {

		constexpr std::uint32_t m_nExternalGraphNodeIdx{ 0x10 };

	} // namespace cnmisexternalgraphslotfillednode__cdefinition

	namespace cnmisexternalposesetnode__cdefinition {

		constexpr std::uint32_t m_nExternalPoseNodeIdx{ 0x10 };

	} // namespace cnmisexternalposesetnode__cdefinition

	namespace cnmistargetsetnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };

	} // namespace cnmistargetsetnode__cdefinition

	namespace cnmlayerblendnode__cdefinition {

		constexpr std::uint32_t m_nBaseNodeIdx{ 0x10 };
		constexpr std::uint32_t m_bOnlySampleBaseRootMotion{ 0x12 };
		constexpr std::uint32_t m_layerDefinition{ 0x18 };

	} // namespace cnmlayerblendnode__cdefinition

	namespace cnmlayerblendnode__layerdefinition_t {

		constexpr std::uint32_t m_nInputNodeIdx{ 0x0 };
		constexpr std::uint32_t m_nWeightValueNodeIdx{ 0x2 };
		constexpr std::uint32_t m_nBoneMaskValueNodeIdx{ 0x4 };
		constexpr std::uint32_t m_nRootMotionWeightValueNodeIdx{ 0x6 };
		constexpr std::uint32_t m_bIsSynchronized{ 0x8 };
		constexpr std::uint32_t m_bIgnoreEvents{ 0x9 };
		constexpr std::uint32_t m_bIsStateMachineLayer{ 0xA };
		constexpr std::uint32_t m_blendMode{ 0xB };

	} // namespace cnmlayerblendnode__layerdefinition_t

	namespace cnmlegacyevent {

		constexpr std::uint32_t m_animEventClassName{ 0x20 };
		constexpr std::uint32_t m_KV{ 0x28 };

	} // namespace cnmlegacyevent

	namespace cnmmaterialattributeevent {

		constexpr std::uint32_t m_attributeName{ 0x20 };
		constexpr std::uint32_t m_attributeNameToken{ 0x28 };
		constexpr std::uint32_t m_x{ 0x30 };
		constexpr std::uint32_t m_y{ 0x70 };
		constexpr std::uint32_t m_z{ 0xB0 };
		constexpr std::uint32_t m_w{ 0xF0 };

	} // namespace cnmmaterialattributeevent

	namespace cnmnotnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };

	} // namespace cnmnotnode__cdefinition

	namespace cnmorientationwarpnode__cdefinition {

		constexpr std::uint32_t m_nClipReferenceNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nTargetValueNodeIdx{ 0x12 };
		constexpr std::uint32_t m_bIsOffsetNode{ 0x14 };
		constexpr std::uint32_t m_bIsOffsetRelativeToCharacter{ 0x15 };
		constexpr std::uint32_t m_bWarpTranslation{ 0x16 };
		constexpr std::uint32_t m_samplingMode{ 0x17 };

	} // namespace cnmorientationwarpnode__cdefinition

	namespace cnmornode__cdefinition {

		constexpr std::uint32_t m_conditionNodeIndices{ 0x10 };

	} // namespace cnmornode__cdefinition

	namespace cnmparameterizedblendnode__blendrange_t {

		constexpr std::uint32_t m_nInputIdx0{ 0x0 };
		constexpr std::uint32_t m_nInputIdx1{ 0x2 };
		constexpr std::uint32_t m_parameterValueRange{ 0x4 };

	} // namespace cnmparameterizedblendnode__blendrange_t

	namespace cnmparameterizedblendnode__cdefinition {

		constexpr std::uint32_t m_sourceNodeIndices{ 0x10 };
		constexpr std::uint32_t m_nInputParameterValueNodeIdx{ 0x38 };
		constexpr std::uint32_t m_bAllowLooping{ 0x3A };

	} // namespace cnmparameterizedblendnode__cdefinition

	namespace cnmparameterizedblendnode__parameterization_t {

		constexpr std::uint32_t m_blendRanges{ 0x0 };
		constexpr std::uint32_t m_parameterRange{ 0x48 };

	} // namespace cnmparameterizedblendnode__parameterization_t

	namespace cnmparameterizedclipselectornode__cdefinition {

		constexpr std::uint32_t m_optionNodeIndices{ 0x10 };
		constexpr std::uint32_t m_optionWeights{ 0x28 };
		constexpr std::uint32_t m_parameterNodeIdx{ 0x38 };
		constexpr std::uint32_t m_bIgnoreInvalidOptions{ 0x3A };
		constexpr std::uint32_t m_bHasWeightsSet{ 0x3B };

	} // namespace cnmparameterizedclipselectornode__cdefinition

	namespace cnmparameterizedselectornode__cdefinition {

		constexpr std::uint32_t m_optionNodeIndices{ 0x10 };
		constexpr std::uint32_t m_optionWeights{ 0x28 };
		constexpr std::uint32_t m_parameterNodeIdx{ 0x38 };
		constexpr std::uint32_t m_bIgnoreInvalidOptions{ 0x3A };
		constexpr std::uint32_t m_bHasWeightsSet{ 0x3B };

	} // namespace cnmparameterizedselectornode__cdefinition

	namespace cnmparticleevent {

		constexpr std::uint32_t m_relevance{ 0x20 };
		constexpr std::uint32_t m_type{ 0x24 };
		constexpr std::uint32_t m_hParticleSystem{ 0x28 };
		constexpr std::uint32_t m_tags{ 0x30 };
		constexpr std::uint32_t m_bStopImmediately{ 0x38 };
		constexpr std::uint32_t m_bDetachFromOwner{ 0x39 };
		constexpr std::uint32_t m_bPlayEndCap{ 0x3A };
		constexpr std::uint32_t m_attachmentPoint0{ 0x40 };
		constexpr std::uint32_t m_attachmentType0{ 0x48 };
		constexpr std::uint32_t m_attachmentPoint1{ 0x50 };
		constexpr std::uint32_t m_attachmentType1{ 0x58 };
		constexpr std::uint32_t m_config{ 0x60 };
		constexpr std::uint32_t m_effectForConfig{ 0x68 };

	} // namespace cnmparticleevent

	namespace cnmpassthroughnode__cdefinition {

		constexpr std::uint32_t m_nChildNodeIdx{ 0x10 };

	} // namespace cnmpassthroughnode__cdefinition

	namespace cnmreferencedgraphnode__cdefinition {

		constexpr std::uint32_t m_nReferencedGraphIdx{ 0x10 };
		constexpr std::uint32_t m_nFallbackNodeIdx{ 0x12 };

	} // namespace cnmreferencedgraphnode__cdefinition

	namespace cnmrootmotiondata {

		constexpr std::uint32_t m_transforms{ 0x0 };
		constexpr std::uint32_t m_nNumFrames{ 0x18 };
		constexpr std::uint32_t m_flAverageLinearVelocity{ 0x1C };
		constexpr std::uint32_t m_flAverageAngularVelocityRadians{ 0x20 };
		constexpr std::uint32_t m_totalDelta{ 0x30 };

	} // namespace cnmrootmotiondata

	namespace cnmrootmotionevent {

		constexpr std::uint32_t m_flBlendTimeSeconds{ 0x20 };

	} // namespace cnmrootmotionevent

	namespace cnmrootmotionoverridenode__cdefinition {

		constexpr std::uint32_t m_desiredMovingVelocityNodeIdx{ 0x18 };
		constexpr std::uint32_t m_desiredFacingDirectionNodeIdx{ 0x1A };
		constexpr std::uint32_t m_linearVelocityLimitNodeIdx{ 0x1C };
		constexpr std::uint32_t m_angularVelocityLimitNodeIdx{ 0x1E };
		constexpr std::uint32_t m_maxLinearVelocity{ 0x20 };
		constexpr std::uint32_t m_maxAngularVelocityRadians{ 0x24 };
		constexpr std::uint32_t m_overrideFlags{ 0x28 };

	} // namespace cnmrootmotionoverridenode__cdefinition

	namespace cnmscalenode__cdefinition {

		constexpr std::uint32_t m_nMaskNodeIdx{ 0x18 };
		constexpr std::uint32_t m_nEnableNodeIdx{ 0x1A };

	} // namespace cnmscalenode__cdefinition

	namespace cnmselectornode__cdefinition {

		constexpr std::uint32_t m_optionNodeIndices{ 0x10 };
		constexpr std::uint32_t m_conditionNodeIndices{ 0x28 };

	} // namespace cnmselectornode__cdefinition

	namespace cnmskeleton {

		constexpr std::uint32_t m_ID{ 0x0 };
		constexpr std::uint32_t m_boneIDs{ 0x8 };
		constexpr std::uint32_t m_parentIndices{ 0x18 };
		constexpr std::uint32_t m_parentSpaceReferencePose{ 0x30 };
		constexpr std::uint32_t m_modelSpaceReferencePose{ 0x48 };
		constexpr std::uint32_t m_numBonesToSampleAtLowLOD{ 0x60 };
		constexpr std::uint32_t m_maskDefinitions{ 0x88 };
		constexpr std::uint32_t m_secondarySkeletons{ 0xA8 };
		constexpr std::uint32_t m_bIsPropSkeleton{ 0xB8 };

	} // namespace cnmskeleton

	namespace cnmskeleton__secondaryskeleton_t {

		constexpr std::uint32_t m_attachToBoneID{ 0x0 };
		constexpr std::uint32_t m_skeleton{ 0x8 };

	} // namespace cnmskeleton__secondaryskeleton_t

	namespace cnmsnapweaponnode__cdefinition {

		constexpr std::uint32_t m_nEnabledNodeIdx{ 0x18 };
		constexpr std::uint32_t m_nLockLeftHandNodeIdx{ 0x1A };
		constexpr std::uint32_t m_flBlendTimeSeconds{ 0x1C };

	} // namespace cnmsnapweaponnode__cdefinition

	namespace cnmsoundevent {

		constexpr std::uint32_t m_relevance{ 0x20 };
		constexpr std::uint32_t m_name{ 0x28 };
		constexpr std::uint32_t m_position{ 0x30 };
		constexpr std::uint32_t m_attachmentName{ 0x38 };
		constexpr std::uint32_t m_tags{ 0x40 };
		constexpr std::uint32_t m_bContinuePlayingSoundAtDurationEnd{ 0x48 };
		constexpr std::uint32_t m_flDurationInterruptionThreshold{ 0x4C };

	} // namespace cnmsoundevent

	namespace cnmspeedscalebasenode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x18 };
		constexpr std::uint32_t m_flDefaultInputValue{ 0x1C };

	} // namespace cnmspeedscalebasenode__cdefinition

	namespace cnmstatecompletedconditionnode__cdefinition {

		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nTransitionDurationOverrideNodeIdx{ 0x12 };
		constexpr std::uint32_t m_flTransitionDurationSeconds{ 0x14 };

	} // namespace cnmstatecompletedconditionnode__cdefinition

	namespace cnmstatemachinenode__cdefinition {

		constexpr std::uint32_t m_stateDefinitions{ 0x10 };
		constexpr std::uint32_t m_nDefaultStateIndex{ 0x130 };

	} // namespace cnmstatemachinenode__cdefinition

	namespace cnmstatemachinenode__statedefinition_t {

		constexpr std::uint32_t m_nStateNodeIdx{ 0x0 };
		constexpr std::uint32_t m_nEntryConditionNodeIdx{ 0x2 };
		constexpr std::uint32_t m_transitionDefinitions{ 0x8 };

	} // namespace cnmstatemachinenode__statedefinition_t

	namespace cnmstatemachinenode__transitiondefinition_t {

		constexpr std::uint32_t m_nTargetStateIdx{ 0x0 };
		constexpr std::uint32_t m_nConditionNodeIdx{ 0x2 };
		constexpr std::uint32_t m_nTransitionNodeIdx{ 0x4 };
		constexpr std::uint32_t m_bCanBeForced{ 0x6 };

	} // namespace cnmstatemachinenode__transitiondefinition_t

	namespace cnmstatenode__cdefinition {

		constexpr std::uint32_t m_nChildNodeIdx{ 0x10 };
		constexpr std::uint32_t m_entryEvents{ 0x18 };
		constexpr std::uint32_t m_executeEvents{ 0x38 };
		constexpr std::uint32_t m_exitEvents{ 0x58 };
		constexpr std::uint32_t m_timedRemainingEvents{ 0x78 };
		constexpr std::uint32_t m_timedElapsedEvents{ 0x90 };
		constexpr std::uint32_t m_nLayerWeightNodeIdx{ 0xA8 };
		constexpr std::uint32_t m_nLayerRootMotionWeightNodeIdx{ 0xAA };
		constexpr std::uint32_t m_nLayerBoneMaskNodeIdx{ 0xAC };
		constexpr std::uint32_t m_bIsOffState{ 0xAE };
		constexpr std::uint32_t m_bUseActualElapsedTimeInStateForTimedEvents{ 0xAF };

	} // namespace cnmstatenode__cdefinition

	namespace cnmstatenode__timedevent_t {

		constexpr std::uint32_t m_ID{ 0x0 };
		constexpr std::uint32_t m_flTimeValueSeconds{ 0x8 };
		constexpr std::uint32_t m_comparisionOperator{ 0xC };

	} // namespace cnmstatenode__timedevent_t

	namespace cnmsynceventindexconditionnode__cdefinition {

		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_triggerMode{ 0x12 };
		constexpr std::uint32_t m_syncEventIdx{ 0x14 };

	} // namespace cnmsynceventindexconditionnode__cdefinition

	namespace cnmsynctrack {

		constexpr std::uint32_t m_syncEvents{ 0x0 };
		constexpr std::uint32_t m_nStartEventOffset{ 0xA8 };

	} // namespace cnmsynctrack

	namespace cnmsynctrack__event_t {

		constexpr std::uint32_t m_ID{ 0x0 };
		constexpr std::uint32_t m_startTime{ 0x8 };
		constexpr std::uint32_t m_duration{ 0xC };

	} // namespace cnmsynctrack__event_t

	namespace cnmsynctrack__eventmarker_t {

		constexpr std::uint32_t m_startTime{ 0x0 };
		constexpr std::uint32_t m_ID{ 0x8 };

	} // namespace cnmsynctrack__eventmarker_t

	namespace cnmtarget {

		constexpr std::uint32_t m_transform{ 0x0 };
		constexpr std::uint32_t m_boneID{ 0x20 };
		constexpr std::uint32_t m_bIsBoneTarget{ 0x28 };
		constexpr std::uint32_t m_bIsUsingBoneSpaceOffsets{ 0x29 };
		constexpr std::uint32_t m_bHasOffsets{ 0x2A };
		constexpr std::uint32_t m_bIsSet{ 0x2B };

	} // namespace cnmtarget

	namespace cnmtargetinfonode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_infoType{ 0x14 };
		constexpr std::uint32_t m_bIsWorldSpaceTarget{ 0x18 };

	} // namespace cnmtargetinfonode__cdefinition

	namespace cnmtargetoffsetnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_bIsBoneSpaceOffset{ 0x12 };
		constexpr std::uint32_t m_rotationOffset{ 0x20 };
		constexpr std::uint32_t m_translationOffset{ 0x30 };

	} // namespace cnmtargetoffsetnode__cdefinition

	namespace cnmtargetpointnode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_bIsWorldSpaceTarget{ 0x12 };

	} // namespace cnmtargetpointnode__cdefinition

	namespace cnmtargetselectornode__cdefinition {

		constexpr std::uint32_t m_optionNodeIndices{ 0x10 };
		constexpr std::uint32_t m_flOrientationScoreWeight{ 0x28 };
		constexpr std::uint32_t m_flPositionScoreWeight{ 0x2C };
		constexpr std::uint32_t m_parameterNodeIdx{ 0x30 };
		constexpr std::uint32_t m_bIgnoreInvalidOptions{ 0x32 };
		constexpr std::uint32_t m_bIsWorldSpaceTarget{ 0x33 };

	} // namespace cnmtargetselectornode__cdefinition

	namespace cnmtargetwarpevent {

		constexpr std::uint32_t m_rule{ 0x20 };
		constexpr std::uint32_t m_algorithm{ 0x21 };

	} // namespace cnmtargetwarpevent

	namespace cnmtargetwarpnode__cdefinition {

		constexpr std::uint32_t m_nClipReferenceNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nTargetValueNodeIdx{ 0x12 };
		constexpr std::uint32_t m_samplingMode{ 0x14 };
		constexpr std::uint32_t m_bAllowTargetUpdate{ 0x15 };
		constexpr std::uint32_t m_bAlignWithTargetAtLastWarpEvent{ 0x16 };
		constexpr std::uint32_t m_flSamplingPositionErrorThresholdSq{ 0x18 };
		constexpr std::uint32_t m_flMaxTangentLength{ 0x1C };
		constexpr std::uint32_t m_flLerpFallbackDistanceThreshold{ 0x20 };
		constexpr std::uint32_t m_flTargetUpdateDistanceThreshold{ 0x24 };
		constexpr std::uint32_t m_flTargetUpdateAngleThresholdRadians{ 0x28 };

	} // namespace cnmtargetwarpnode__cdefinition

	namespace cnmtimeconditionnode__cdefinition {

		constexpr std::uint32_t m_sourceStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x12 };
		constexpr std::uint32_t m_flComparand{ 0x14 };
		constexpr std::uint32_t m_type{ 0x18 };
		constexpr std::uint32_t m_operator{ 0x19 };

	} // namespace cnmtimeconditionnode__cdefinition

	namespace cnmtransitionevent {

		constexpr std::uint32_t m_rule{ 0x20 };
		constexpr std::uint32_t m_ID{ 0x28 };

	} // namespace cnmtransitionevent

	namespace cnmtransitioneventconditionnode__cdefinition {

		constexpr std::uint32_t m_requireRuleID{ 0x10 };
		constexpr std::uint32_t m_eventConditionRules{ 0x18 };
		constexpr std::uint32_t m_nSourceStateNodeIdx{ 0x1C };
		constexpr std::uint32_t m_ruleCondition{ 0x1E };

	} // namespace cnmtransitioneventconditionnode__cdefinition

	namespace cnmtransitionnode__cdefinition {

		constexpr std::uint32_t m_nTargetStateNodeIdx{ 0x10 };
		constexpr std::uint32_t m_nDurationOverrideNodeIdx{ 0x12 };
		constexpr std::uint32_t m_timeOffsetOverrideNodeIdx{ 0x14 };
		constexpr std::uint32_t m_startBoneMaskNodeIdx{ 0x16 };
		constexpr std::uint32_t m_flDuration{ 0x18 };
		constexpr std::uint32_t m_boneMaskBlendInTimePercentage{ 0x1C };
		constexpr std::uint32_t m_flTimeOffset{ 0x20 };
		constexpr std::uint32_t m_transitionOptions{ 0x24 };
		constexpr std::uint32_t m_targetSyncIDNodeIdx{ 0x28 };
		constexpr std::uint32_t m_blendWeightEasing{ 0x2A };
		constexpr std::uint32_t m_rootMotionBlend{ 0x2B };

	} // namespace cnmtransitionnode__cdefinition

	namespace cnmtwoboneiknode__cdefinition {

		constexpr std::uint32_t m_effectorBoneID{ 0x18 };
		constexpr std::uint32_t m_nEffectorTargetNodeIdx{ 0x20 };
		constexpr std::uint32_t m_nEnabledNodeIdx{ 0x22 };
		constexpr std::uint32_t m_flBlendTimeSeconds{ 0x24 };
		constexpr std::uint32_t m_blendMode{ 0x28 };
		constexpr std::uint32_t m_bIsTargetInWorldSpace{ 0x29 };
		constexpr std::uint32_t m_flReferencePoseTwistWeight{ 0x2C };

	} // namespace cnmtwoboneiknode__cdefinition

	namespace cnmtwoboneiktask {

		constexpr std::uint32_t m_nEffectorBoneIdx{ 0x58 };
		constexpr std::uint32_t m_nEffectorTargetBoneIdx{ 0x5C };
		constexpr std::uint32_t m_targetTransform{ 0x60 };
		constexpr std::uint32_t m_effectorTarget{ 0x80 };
		constexpr std::uint32_t m_blendMode{ 0xB0 };
		constexpr std::uint32_t m_flBlendWeight{ 0xB4 };
		constexpr std::uint32_t m_bIsTargetInWorldSpace{ 0xB8 };
		constexpr std::uint32_t m_bIsRunningFromDeserializedData{ 0xB9 };
		constexpr std::uint32_t m_flReferencePoseTwistWeight{ 0xBC };
		constexpr std::uint32_t m_debugEffectorBoneID{ 0xC0 };

	} // namespace cnmtwoboneiktask

	namespace cnmvectorcreatenode__cdefinition {

		constexpr std::uint32_t m_inputVectorValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_inputValueXNodeIdx{ 0x12 };
		constexpr std::uint32_t m_inputValueYNodeIdx{ 0x14 };
		constexpr std::uint32_t m_inputValueZNodeIdx{ 0x16 };

	} // namespace cnmvectorcreatenode__cdefinition

	namespace cnmvectorinfonode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };
		constexpr std::uint32_t m_desiredInfo{ 0x12 };

	} // namespace cnmvectorinfonode__cdefinition

	namespace cnmvectornegatenode__cdefinition {

		constexpr std::uint32_t m_nInputValueNodeIdx{ 0x10 };

	} // namespace cnmvectornegatenode__cdefinition

	namespace cnmvirtualparameterbonemasknode__cdefinition {

		constexpr std::uint32_t m_nChildNodeIdx{ 0x10 };

	} // namespace cnmvirtualparameterbonemasknode__cdefinition

	namespace cnmvirtualparameterboolnode__cdefinition {

		constexpr std::uint32_t m_nChildNodeIdx{ 0x10 };

	} // namespace cnmvirtualparameterboolnode__cdefinition

	namespace cnmvirtualparameterfloatnode__cdefinition {

		constexpr std::uint32_t m_nChildNodeIdx{ 0x10 };

	} // namespace cnmvirtualparameterfloatnode__cdefinition

	namespace cnmvirtualparameteridnode__cdefinition {

		constexpr std::uint32_t m_nChildNodeIdx{ 0x10 };

	} // namespace cnmvirtualparameteridnode__cdefinition

	namespace cnmvirtualparametertargetnode__cdefinition {

		constexpr std::uint32_t m_nChildNodeIdx{ 0x10 };

	} // namespace cnmvirtualparametertargetnode__cdefinition

	namespace cnmvirtualparametervectornode__cdefinition {

		constexpr std::uint32_t m_nChildNodeIdx{ 0x10 };

	} // namespace cnmvirtualparametervectornode__cdefinition

	namespace codegenaabb_t {

		constexpr std::uint32_t m_vMinBounds{ 0x0 };
		constexpr std::uint32_t m_vMaxBounds{ 0xC };

	} // namespace codegenaabb_t

	namespace compmatmutatorcondition_t {

		constexpr std::uint32_t m_nMutatorCondition{ 0x0 };
		constexpr std::uint32_t m_strMutatorConditionContainerName{ 0x8 };
		constexpr std::uint32_t m_strMutatorConditionContainerVarName{ 0x10 };
		constexpr std::uint32_t m_strMutatorConditionContainerVarValue{ 0x18 };
		constexpr std::uint32_t m_bPassWhenTrue{ 0x20 };

	} // namespace compmatmutatorcondition_t

	namespace compmatpropertymutator_t {

		constexpr std::uint32_t m_bEnabled{ 0x0 };
		constexpr std::uint32_t m_nMutatorCommandType{ 0x4 };
		constexpr std::uint32_t m_strInitWith_Container{ 0x8 };
		constexpr std::uint32_t m_strCopyProperty_InputContainerSrc{ 0x10 };
		constexpr std::uint32_t m_strCopyProperty_InputContainerProperty{ 0x18 };
		constexpr std::uint32_t m_strCopyProperty_TargetProperty{ 0x20 };
		constexpr std::uint32_t m_strRandomRollInputVars_SeedInputVar{ 0x28 };
		constexpr std::uint32_t m_vecRandomRollInputVars_InputVarsToRoll{ 0x30 };
		constexpr std::uint32_t m_strCopyMatchingKeys_InputContainerSrc{ 0x48 };
		constexpr std::uint32_t m_strCopyKeysWithSuffix_InputContainerSrc{ 0x50 };
		constexpr std::uint32_t m_strCopyKeysWithSuffix_FindSuffix{ 0x58 };
		constexpr std::uint32_t m_strCopyKeysWithSuffix_ReplaceSuffix{ 0x60 };
		constexpr std::uint32_t m_nSetValue_Value{ 0x68 };
		constexpr std::uint32_t m_strGenerateTexture_TargetParam{ 0x2F0 };
		constexpr std::uint32_t m_strGenerateTexture_InitialContainer{ 0x2F8 };
		constexpr std::uint32_t m_nResolution{ 0x300 };
		constexpr std::uint32_t m_bIsScratchTarget{ 0x304 };
		constexpr std::uint32_t m_strCompressionFormat{ 0x308 };
		constexpr std::uint32_t m_bSplatDebugInfo{ 0x310 };
		constexpr std::uint32_t m_bCaptureInRenderDoc{ 0x311 };
		constexpr std::uint32_t m_vecTexGenInstructions{ 0x318 };
		constexpr std::uint32_t m_vecConditionalMutators{ 0x330 };
		constexpr std::uint32_t m_strPopInputQueue_Container{ 0x348 };
		constexpr std::uint32_t m_strDrawText_InputContainerSrc{ 0x350 };
		constexpr std::uint32_t m_strDrawText_InputContainerProperty{ 0x358 };
		constexpr std::uint32_t m_vecDrawText_Position{ 0x360 };
		constexpr std::uint32_t m_colDrawText_Color{ 0x368 };
		constexpr std::uint32_t m_strDrawText_Font{ 0x370 };
		constexpr std::uint32_t m_vecConditions{ 0x378 };

	} // namespace compmatpropertymutator_t

	namespace compositematerial_t {

		constexpr std::uint32_t m_TargetKVs{ 0x8 };
		constexpr std::uint32_t m_PreGenerationKVs{ 0x18 };
		constexpr std::uint32_t m_FinalKVs{ 0x58 };
		constexpr std::uint32_t m_vecGeneratedTextures{ 0x80 };

	} // namespace compositematerial_t

	namespace compositematerialassemblyprocedure_t {

		constexpr std::uint32_t m_vecCompMatIncludes{ 0x0 };
		constexpr std::uint32_t m_vecMatchFilters{ 0x18 };
		constexpr std::uint32_t m_vecCompositeInputContainers{ 0x30 };
		constexpr std::uint32_t m_vecPropertyMutators{ 0x48 };

	} // namespace compositematerialassemblyprocedure_t

	namespace compositematerialeditorpoint_t {

		constexpr std::uint32_t m_ModelName{ 0x0 };
		constexpr std::uint32_t m_nSequenceIndex{ 0xE0 };
		constexpr std::uint32_t m_flCycle{ 0xE4 };
		constexpr std::uint32_t m_KVModelStateChoices{ 0xE8 };
		constexpr std::uint32_t m_bEnableChildModel{ 0xF8 };
		constexpr std::uint32_t m_ChildModelName{ 0x100 };
		constexpr std::uint32_t m_vecCompositeMaterialAssemblyProcedures{ 0x1E0 };
		constexpr std::uint32_t m_vecCompositeMaterials{ 0x1F8 };

	} // namespace compositematerialeditorpoint_t

	namespace compositematerialinputcontainer_t {

		constexpr std::uint32_t m_bEnabled{ 0x0 };
		constexpr std::uint32_t m_nCompositeMaterialInputContainerSourceType{ 0x4 };
		constexpr std::uint32_t m_strSpecificContainerMaterial{ 0x8 };
		constexpr std::uint32_t m_strAttrName{ 0xE8 };
		constexpr std::uint32_t m_strAlias{ 0xF0 };
		constexpr std::uint32_t m_vecLooseVariables{ 0xF8 };
		constexpr std::uint32_t m_strAttrNameForVar{ 0x110 };
		constexpr std::uint32_t m_bExposeExternally{ 0x118 };

	} // namespace compositematerialinputcontainer_t

	namespace compositematerialinputloosevariable_t {

		constexpr std::uint32_t m_strName{ 0x0 };
		constexpr std::uint32_t m_bExposeExternally{ 0x8 };
		constexpr std::uint32_t m_strExposedFriendlyName{ 0x10 };
		constexpr std::uint32_t m_strExposedFriendlyGroupName{ 0x18 };
		constexpr std::uint32_t m_bExposedVariableIsFixedRange{ 0x20 };
		constexpr std::uint32_t m_strExposedVisibleWhenTrue{ 0x28 };
		constexpr std::uint32_t m_strExposedHiddenWhenTrue{ 0x30 };
		constexpr std::uint32_t m_strExposedValueList{ 0x38 };
		constexpr std::uint32_t m_nVariableType{ 0x40 };
		constexpr std::uint32_t m_bValueBoolean{ 0x44 };
		constexpr std::uint32_t m_nValueIntX{ 0x48 };
		constexpr std::uint32_t m_nValueIntY{ 0x4C };
		constexpr std::uint32_t m_nValueIntZ{ 0x50 };
		constexpr std::uint32_t m_nValueIntW{ 0x54 };
		constexpr std::uint32_t m_bHasFloatBounds{ 0x58 };
		constexpr std::uint32_t m_flValueFloatX{ 0x5C };
		constexpr std::uint32_t m_flValueFloatX_Min{ 0x60 };
		constexpr std::uint32_t m_flValueFloatX_Max{ 0x64 };
		constexpr std::uint32_t m_flValueFloatY{ 0x68 };
		constexpr std::uint32_t m_flValueFloatY_Min{ 0x6C };
		constexpr std::uint32_t m_flValueFloatY_Max{ 0x70 };
		constexpr std::uint32_t m_flValueFloatZ{ 0x74 };
		constexpr std::uint32_t m_flValueFloatZ_Min{ 0x78 };
		constexpr std::uint32_t m_flValueFloatZ_Max{ 0x7C };
		constexpr std::uint32_t m_flValueFloatW{ 0x80 };
		constexpr std::uint32_t m_flValueFloatW_Min{ 0x84 };
		constexpr std::uint32_t m_flValueFloatW_Max{ 0x88 };
		constexpr std::uint32_t m_cValueColor4{ 0x8C };
		constexpr std::uint32_t m_nValueSystemVar{ 0x90 };
		constexpr std::uint32_t m_strResourceMaterial{ 0x98 };
		constexpr std::uint32_t m_strTextureContentAssetPath{ 0x178 };
		constexpr std::uint32_t m_strTextureRuntimeResourcePath{ 0x180 };
		constexpr std::uint32_t m_strTextureCompilationVtexTemplate{ 0x260 };
		constexpr std::uint32_t m_nTextureType{ 0x268 };
		constexpr std::uint32_t m_strString{ 0x270 };
		constexpr std::uint32_t m_strPanoramaPanelPath{ 0x278 };
		constexpr std::uint32_t m_nPanoramaRenderRes{ 0x280 };

	} // namespace compositematerialinputloosevariable_t

	namespace compositematerialmatchfilter_t {

		constexpr std::uint32_t m_nCompositeMaterialMatchFilterType{ 0x0 };
		constexpr std::uint32_t m_strMatchFilter{ 0x8 };
		constexpr std::uint32_t m_strMatchValue{ 0x10 };
		constexpr std::uint32_t m_bPassWhenTrue{ 0x18 };

	} // namespace compositematerialmatchfilter_t

	namespace constantinfo_t {

		constexpr std::uint32_t m_name{ 0x0 };
		constexpr std::uint32_t m_nameToken{ 0x8 };
		constexpr std::uint32_t m_flValue{ 0xC };

	} // namespace constantinfo_t

	namespace countdowntimer {

		constexpr std::uint32_t m_duration{ 0x8 };
		constexpr std::uint32_t m_timestamp{ 0xC };
		constexpr std::uint32_t m_timescale{ 0x10 };
		constexpr std::uint32_t m_nWorldGroupId{ 0x14 };

	} // namespace countdowntimer

	namespace cpathnode {

		constexpr std::uint32_t m_vInTangentLocal{ 0x608 };
		constexpr std::uint32_t m_vOutTangentLocal{ 0x614 };
		constexpr std::uint32_t m_strParentPathUniqueID{ 0x620 };
		constexpr std::uint32_t m_strPathNodeParameter{ 0x628 };
		constexpr std::uint32_t m_xWSPrevParent{ 0x630 };
		constexpr std::uint32_t m_hPath{ 0x650 };

	} // namespace cpathnode

	namespace cpathqueryutil {

		constexpr std::uint32_t m_PathToEntityTransform{ 0x10 };
		constexpr std::uint32_t m_vecPathSamplePositions{ 0x30 };
		constexpr std::uint32_t m_vecPathSampleParameters{ 0x48 };
		constexpr std::uint32_t m_vecPathSampleDistances{ 0x60 };
		constexpr std::uint32_t m_bIsClosedLoop{ 0x78 };

	} // namespace cpathqueryutil

	namespace cpathsimple {

		constexpr std::uint32_t m_CPathQueryComponent{ 0x610 };
		constexpr std::uint32_t m_pathString{ 0x700 };
		constexpr std::uint32_t m_bClosedLoop{ 0x708 };

	} // namespace cpathsimple

	namespace cpathwithdynamicnodes {

		constexpr std::uint32_t m_vecPathNodes{ 0x710 };
		constexpr std::uint32_t m_xInitialPathWorldToLocal{ 0x730 };

	} // namespace cpathwithdynamicnodes

	namespace cphysicsbodygamemarkup {

		constexpr std::uint32_t m_TargetBody{ 0x0 };
		constexpr std::uint32_t m_Tag{ 0x8 };

	} // namespace cphysicsbodygamemarkup

	namespace cphysicsbodygamemarkupdata {

		constexpr std::uint32_t m_PhysicsBodyMarkupByBoneName{ 0x0 };

	} // namespace cphysicsbodygamemarkupdata

	namespace cplayer_cameraservices {

		constexpr std::uint32_t m_vecCsViewPunchAngle{ 0x48 };
		constexpr std::uint32_t m_nCsViewPunchAngleTick{ 0x54 };
		constexpr std::uint32_t m_flCsViewPunchAngleTickRatio{ 0x58 };
		constexpr std::uint32_t m_PlayerFog{ 0x60 };
		constexpr std::uint32_t m_hColorCorrectionCtrl{ 0xA0 };
		constexpr std::uint32_t m_hViewEntity{ 0xA4 };
		constexpr std::uint32_t m_hTonemapController{ 0xA8 };
		constexpr std::uint32_t m_audio{ 0xB0 };
		constexpr std::uint32_t m_PostProcessingVolumes{ 0x128 };
		constexpr std::uint32_t m_flOldPlayerZ{ 0x140 };
		constexpr std::uint32_t m_flOldPlayerViewOffsetZ{ 0x144 };
		constexpr std::uint32_t m_CurrentFog{ 0x148 };
		constexpr std::uint32_t m_hOldFogController{ 0x1B0 };
		constexpr std::uint32_t m_bOverrideFogColor{ 0x1B4 };
		constexpr std::uint32_t m_OverrideFogColor{ 0x1B9 };
		constexpr std::uint32_t m_bOverrideFogStartEnd{ 0x1CD };
		constexpr std::uint32_t m_fOverrideFogStart{ 0x1D4 };
		constexpr std::uint32_t m_fOverrideFogEnd{ 0x1E8 };
		constexpr std::uint32_t m_hActivePostProcessingVolume{ 0x1FC };
		constexpr std::uint32_t m_angDemoViewAngles{ 0x200 };

	} // namespace cplayer_cameraservices

	namespace cplayer_movementservices {

		constexpr std::uint32_t m_nImpulse{ 0x48 };
		constexpr std::uint32_t m_nButtons{ 0x50 };
		constexpr std::uint32_t m_nQueuedButtonDownMask{ 0x70 };
		constexpr std::uint32_t m_nQueuedButtonChangeMask{ 0x78 };
		constexpr std::uint32_t m_nButtonDoublePressed{ 0x80 };
		constexpr std::uint32_t m_pButtonPressedCmdNumber{ 0x88 };
		constexpr std::uint32_t m_nLastCommandNumberProcessed{ 0x188 };
		constexpr std::uint32_t m_nToggleButtonDownMask{ 0x190 };
		constexpr std::uint32_t m_flMaxspeed{ 0x1A0 };
		constexpr std::uint32_t m_arrForceSubtickMoveWhen{ 0x1A4 };
		constexpr std::uint32_t m_flForwardMove{ 0x1B4 };
		constexpr std::uint32_t m_flLeftMove{ 0x1B8 };
		constexpr std::uint32_t m_flUpMove{ 0x1BC };
		constexpr std::uint32_t m_vecLastMovementImpulses{ 0x1C0 };
		constexpr std::uint32_t m_vecOldViewAngles{ 0x228 };

	} // namespace cplayer_movementservices

	namespace cplayer_movementservices_humanoid {

		constexpr std::uint32_t m_flStepSoundTime{ 0x240 };
		constexpr std::uint32_t m_flFallVelocity{ 0x244 };
		constexpr std::uint32_t m_groundNormal{ 0x248 };
		constexpr std::uint32_t m_flSurfaceFriction{ 0x254 };
		constexpr std::uint32_t m_surfaceProps{ 0x258 };
		constexpr std::uint32_t m_nStepside{ 0x268 };

	} // namespace cplayer_movementservices_humanoid

	namespace cplayer_observerservices {

		constexpr std::uint32_t m_iObserverMode{ 0x48 };
		constexpr std::uint32_t m_hObserverTarget{ 0x4C };
		constexpr std::uint32_t m_iObserverLastMode{ 0x50 };
		constexpr std::uint32_t m_bForcedObserverMode{ 0x54 };
		constexpr std::uint32_t m_flObserverChaseDistance{ 0x58 };
		constexpr std::uint32_t m_flObserverChaseDistanceCalcTime{ 0x5C };

	} // namespace cplayer_observerservices

	namespace cplayer_weaponservices {

		constexpr std::uint32_t m_hMyWeapons{ 0x48 };
		constexpr std::uint32_t m_hActiveWeapon{ 0x60 };
		constexpr std::uint32_t m_hLastWeapon{ 0x64 };
		constexpr std::uint32_t m_iAmmo{ 0x68 };

	} // namespace cplayer_weaponservices

	namespace cplayercontrollercomponent {

		constexpr std::uint32_t __m_pChainEntity{ 0x8 };

	} // namespace cplayercontrollercomponent

	namespace cplayerpawncomponent {

		constexpr std::uint32_t __m_pChainEntity{ 0x8 };

	} // namespace cplayerpawncomponent

	namespace cpointchildmodifier {

		constexpr std::uint32_t m_bOrphanInsteadOfDeletingChildrenOnRemove{ 0x608 };

	} // namespace cpointchildmodifier

	namespace cpointoffscreenindicatorui {

		constexpr std::uint32_t m_bBeenEnabled{ 0x10E0 };
		constexpr std::uint32_t m_bHide{ 0x10E1 };
		constexpr std::uint32_t m_flSeenTargetTime{ 0x10E4 };
		constexpr std::uint32_t m_pTargetPanel{ 0x10E8 };

	} // namespace cpointoffscreenindicatorui

	namespace cpointorient {

		constexpr std::uint32_t m_iszSpawnTargetName{ 0x608 };
		constexpr std::uint32_t m_hTarget{ 0x610 };
		constexpr std::uint32_t m_bActive{ 0x614 };
		constexpr std::uint32_t m_nGoalDirection{ 0x618 };
		constexpr std::uint32_t m_nConstraint{ 0x61C };
		constexpr std::uint32_t m_flMaxTurnRate{ 0x620 };
		constexpr std::uint32_t m_flLastGameTime{ 0x624 };

	} // namespace cpointorient

	namespace cpointtemplate {

		constexpr std::uint32_t m_iszWorldName{ 0x608 };
		constexpr std::uint32_t m_iszSource2EntityLumpName{ 0x610 };
		constexpr std::uint32_t m_iszEntityFilterName{ 0x618 };
		constexpr std::uint32_t m_flTimeoutInterval{ 0x620 };
		constexpr std::uint32_t m_bAsynchronouslySpawnEntities{ 0x624 };
		constexpr std::uint32_t m_clientOnlyEntityBehavior{ 0x628 };
		constexpr std::uint32_t m_ownerSpawnGroupType{ 0x62C };
		constexpr std::uint32_t m_createdSpawnGroupHandles{ 0x630 };
		constexpr std::uint32_t m_SpawnedEntityHandles{ 0x648 };
		constexpr std::uint32_t m_ScriptSpawnCallback{ 0x660 };
		constexpr std::uint32_t m_ScriptCallbackScope{ 0x668 };

	} // namespace cpointtemplate

	namespace cprecipitationvdata {

		constexpr std::uint32_t m_szParticlePrecipitationEffect{ 0x28 };
		constexpr std::uint32_t m_flInnerDistance{ 0x108 };
		constexpr std::uint32_t m_nAttachType{ 0x10C };
		constexpr std::uint32_t m_bBatchSameVolumeType{ 0x110 };
		constexpr std::uint32_t m_nRTEnvCP{ 0x114 };
		constexpr std::uint32_t m_nRTEnvCPComponent{ 0x118 };
		constexpr std::uint32_t m_szModifier{ 0x120 };

	} // namespace cprecipitationvdata

	namespace cpropdatacomponent {

		constexpr std::uint32_t m_flDmgModBullet{ 0x10 };
		constexpr std::uint32_t m_flDmgModClub{ 0x14 };
		constexpr std::uint32_t m_flDmgModExplosive{ 0x18 };
		constexpr std::uint32_t m_flDmgModFire{ 0x1C };
		constexpr std::uint32_t m_iszPhysicsDamageTableName{ 0x20 };
		constexpr std::uint32_t m_iszBasePropData{ 0x28 };
		constexpr std::uint32_t m_nInteractions{ 0x30 };
		constexpr std::uint32_t m_bSpawnMotionDisabled{ 0x34 };
		constexpr std::uint32_t m_nDisableTakePhysicsDamageSpawnFlag{ 0x38 };
		constexpr std::uint32_t m_nMotionDisabledSpawnFlag{ 0x3C };

	} // namespace cpropdatacomponent

	namespace cpulse_blackboardreference {

		constexpr std::uint32_t m_hBlackboardResource{ 0x0 };
		constexpr std::uint32_t m_BlackboardResource{ 0x8 };
		constexpr std::uint32_t m_nNodeID{ 0x18 };
		constexpr std::uint32_t m_NodeName{ 0x20 };

	} // namespace cpulse_blackboardreference

	namespace cpulse_callinfo {

		constexpr std::uint32_t m_PortName{ 0x0 };
		constexpr std::uint32_t m_nEditorNodeID{ 0x10 };
		constexpr std::uint32_t m_RegisterMap{ 0x18 };
		constexpr std::uint32_t m_CallMethodID{ 0x48 };
		constexpr std::uint32_t m_nSrcChunk{ 0x4C };
		constexpr std::uint32_t m_nSrcInstruction{ 0x50 };

	} // namespace cpulse_callinfo

	namespace cpulse_chunk {

		constexpr std::uint32_t m_Instructions{ 0x0 };
		constexpr std::uint32_t m_Registers{ 0x10 };
		constexpr std::uint32_t m_InstructionDebugInfos{ 0x20 };

	} // namespace cpulse_chunk

	namespace cpulse_constant {

		constexpr std::uint32_t m_Type{ 0x0 };
		constexpr std::uint32_t m_Value{ 0x18 };

	} // namespace cpulse_constant

	namespace cpulse_domainvalue {

		constexpr std::uint32_t m_nType{ 0x0 };
		constexpr std::uint32_t m_Value{ 0x8 };
		constexpr std::uint32_t m_RequiredRuntimeType{ 0x10 };

	} // namespace cpulse_domainvalue

	namespace cpulse_instructiondebug {

		constexpr std::uint32_t m_nFlowNodeID{ 0x0 };
		constexpr std::uint32_t m_nValueNodeID{ 0x4 };
		constexpr std::uint32_t m_SequencePointName{ 0x8 };

	} // namespace cpulse_instructiondebug

	namespace cpulse_invokebinding {

		constexpr std::uint32_t m_RegisterMap{ 0x0 };
		constexpr std::uint32_t m_FuncName{ 0x30 };
		constexpr std::uint32_t m_nCellIndex{ 0x40 };
		constexpr std::uint32_t m_nSrcChunk{ 0x44 };
		constexpr std::uint32_t m_nSrcInstruction{ 0x48 };

	} // namespace cpulse_invokebinding

	namespace cpulse_outflowconnection {

		constexpr std::uint32_t m_SourceOutflowName{ 0x0 };
		constexpr std::uint32_t m_nDestChunk{ 0x10 };
		constexpr std::uint32_t m_nInstruction{ 0x14 };
		constexpr std::uint32_t m_OutflowRegisterMap{ 0x18 };

	} // namespace cpulse_outflowconnection

	namespace cpulse_outputconnection {

		constexpr std::uint32_t m_SourceOutput{ 0x0 };
		constexpr std::uint32_t m_TargetEntity{ 0x10 };
		constexpr std::uint32_t m_TargetInput{ 0x20 };
		constexpr std::uint32_t m_Param{ 0x30 };

	} // namespace cpulse_outputconnection

	namespace cpulse_publicoutput {

		constexpr std::uint32_t m_Name{ 0x0 };
		constexpr std::uint32_t m_Description{ 0x10 };
		constexpr std::uint32_t m_Args{ 0x18 };

	} // namespace cpulse_publicoutput

	namespace cpulse_registerinfo {

		constexpr std::uint32_t m_nReg{ 0x0 };
		constexpr std::uint32_t m_Type{ 0x8 };
		constexpr std::uint32_t m_OriginName{ 0x20 };
		constexpr std::uint32_t m_nWrittenByInstruction{ 0x58 };
		constexpr std::uint32_t m_nLastReadByInstruction{ 0x5C };

	} // namespace cpulse_registerinfo

	namespace cpulse_variable {

		constexpr std::uint32_t m_Name{ 0x0 };
		constexpr std::uint32_t m_Description{ 0x10 };
		constexpr std::uint32_t m_Type{ 0x18 };
		constexpr std::uint32_t m_DefaultValue{ 0x30 };
		constexpr std::uint32_t m_nKeysSource{ 0x44 };
		constexpr std::uint32_t m_bIsPublicBlackboardVariable{ 0x48 };
		constexpr std::uint32_t m_bIsObservable{ 0x49 };
		constexpr std::uint32_t m_nEditorNodeID{ 0x4C };

	} // namespace cpulse_variable

	namespace cpulsecell_base {

		constexpr std::uint32_t m_nEditorNodeID{ 0x8 };

	} // namespace cpulsecell_base

	namespace cpulsecell_baselerp {

		constexpr std::uint32_t m_WakeResume{ 0x48 };

	} // namespace cpulsecell_baselerp

	namespace cpulsecell_baselerp__cursorstate_t {

		constexpr std::uint32_t m_StartTime{ 0x0 };
		constexpr std::uint32_t m_EndTime{ 0x4 };

	} // namespace cpulsecell_baselerp__cursorstate_t

	namespace cpulsecell_booleanswitchstate {

		constexpr std::uint32_t m_Condition{ 0x48 };
		constexpr std::uint32_t m_SubGraph{ 0xC0 };
		constexpr std::uint32_t m_WhenTrue{ 0x108 };
		constexpr std::uint32_t m_WhenFalse{ 0x150 };

	} // namespace cpulsecell_booleanswitchstate

	namespace cpulsecell_cursorqueue {

		constexpr std::uint32_t m_nCursorsAllowedToRunParallel{ 0x98 };

	} // namespace cpulsecell_cursorqueue

	namespace cpulsecell_firecursors {

		constexpr std::uint32_t m_Outflows{ 0x48 };
		constexpr std::uint32_t m_bWaitForChildOutflows{ 0x60 };
		constexpr std::uint32_t m_OnFinished{ 0x68 };
		constexpr std::uint32_t m_OnCanceled{ 0xB0 };

	} // namespace cpulsecell_firecursors

	namespace cpulsecell_inflow_baseentrypoint {

		constexpr std::uint32_t m_EntryChunk{ 0x48 };
		constexpr std::uint32_t m_RegisterMap{ 0x50 };

	} // namespace cpulsecell_inflow_baseentrypoint

	namespace cpulsecell_inflow_entoutputhandler {

		constexpr std::uint32_t m_SourceEntity{ 0x80 };
		constexpr std::uint32_t m_SourceOutput{ 0x90 };
		constexpr std::uint32_t m_ExpectedParamType{ 0xA0 };

	} // namespace cpulsecell_inflow_entoutputhandler

	namespace cpulsecell_inflow_eventhandler {

		constexpr std::uint32_t m_EventName{ 0x80 };

	} // namespace cpulsecell_inflow_eventhandler

	namespace cpulsecell_inflow_graphhook {

		constexpr std::uint32_t m_HookName{ 0x80 };

	} // namespace cpulsecell_inflow_graphhook

	namespace cpulsecell_inflow_method {

		constexpr std::uint32_t m_MethodName{ 0x80 };
		constexpr std::uint32_t m_Description{ 0x90 };
		constexpr std::uint32_t m_bIsPublic{ 0x98 };
		constexpr std::uint32_t m_ReturnType{ 0xA0 };
		constexpr std::uint32_t m_Args{ 0xB8 };

	} // namespace cpulsecell_inflow_method

	namespace cpulsecell_inflow_observablevariablelistener {

		constexpr std::uint32_t m_nBlackboardReference{ 0x80 };
		constexpr std::uint32_t m_bSelfReference{ 0x82 };

	} // namespace cpulsecell_inflow_observablevariablelistener

	namespace cpulsecell_inflow_wait {

		constexpr std::uint32_t m_WakeResume{ 0x48 };

	} // namespace cpulsecell_inflow_wait

	namespace cpulsecell_inflow_yield {

		constexpr std::uint32_t m_UnyieldResume{ 0x48 };

	} // namespace cpulsecell_inflow_yield

	namespace cpulsecell_inlinenodeskipselector {

		constexpr std::uint32_t m_nFlowNodeID{ 0x48 };
		constexpr std::uint32_t m_bAnd{ 0x4C };
		constexpr std::uint32_t m_PassOutflow{ 0x50 };
		constexpr std::uint32_t m_FailOutflow{ 0x68 };

	} // namespace cpulsecell_inlinenodeskipselector

	namespace cpulsecell_intervaltimer {

		constexpr std::uint32_t m_Completed{ 0x48 };
		constexpr std::uint32_t m_OnInterval{ 0x90 };

	} // namespace cpulsecell_intervaltimer

	namespace cpulsecell_intervaltimer__cursorstate_t {

		constexpr std::uint32_t m_StartTime{ 0x0 };
		constexpr std::uint32_t m_EndTime{ 0x4 };
		constexpr std::uint32_t m_flWaitInterval{ 0x8 };
		constexpr std::uint32_t m_flWaitIntervalHigh{ 0xC };
		constexpr std::uint32_t m_bCompleteOnNextWake{ 0x10 };

	} // namespace cpulsecell_intervaltimer__cursorstate_t

	namespace cpulsecell_isrequirementvalid__criteria_t {

		constexpr std::uint32_t m_bIsValid{ 0x0 };

	} // namespace cpulsecell_isrequirementvalid__criteria_t

	namespace cpulsecell_lerpcamerasettings {

		constexpr std::uint32_t m_flSeconds{ 0x90 };
		constexpr std::uint32_t m_Start{ 0x94 };
		constexpr std::uint32_t m_End{ 0xA4 };

	} // namespace cpulsecell_lerpcamerasettings

	namespace cpulsecell_lerpcamerasettings__cursorstate_t {

		constexpr std::uint32_t m_hCamera{ 0x8 };
		constexpr std::uint32_t m_OverlaidStart{ 0xC };
		constexpr std::uint32_t m_OverlaidEnd{ 0x1C };

	} // namespace cpulsecell_lerpcamerasettings__cursorstate_t

	namespace cpulsecell_limitcount {

		constexpr std::uint32_t m_nLimitCount{ 0x48 };

	} // namespace cpulsecell_limitcount

	namespace cpulsecell_limitcount__criteria_t {

		constexpr std::uint32_t m_bLimitCountPasses{ 0x0 };

	} // namespace cpulsecell_limitcount__criteria_t

	namespace cpulsecell_limitcount__instancestate_t {

		constexpr std::uint32_t m_nCurrentCount{ 0x0 };

	} // namespace cpulsecell_limitcount__instancestate_t

	namespace cpulsecell_outflow_cycleordered {

		constexpr std::uint32_t m_Outputs{ 0x48 };

	} // namespace cpulsecell_outflow_cycleordered

	namespace cpulsecell_outflow_cycleordered__instancestate_t {

		constexpr std::uint32_t m_nNextIndex{ 0x0 };

	} // namespace cpulsecell_outflow_cycleordered__instancestate_t

	namespace cpulsecell_outflow_cyclerandom {

		constexpr std::uint32_t m_Outputs{ 0x48 };

	} // namespace cpulsecell_outflow_cyclerandom

	namespace cpulsecell_outflow_cycleshuffled {

		constexpr std::uint32_t m_Outputs{ 0x48 };

	} // namespace cpulsecell_outflow_cycleshuffled

	namespace cpulsecell_outflow_cycleshuffled__instancestate_t {

		constexpr std::uint32_t m_Shuffle{ 0x0 };
		constexpr std::uint32_t m_nNextShuffle{ 0x20 };

	} // namespace cpulsecell_outflow_cycleshuffled__instancestate_t

	namespace cpulsecell_pickbestoutflowselector {

		constexpr std::uint32_t m_nCheckType{ 0x48 };
		constexpr std::uint32_t m_OutflowList{ 0x50 };

	} // namespace cpulsecell_pickbestoutflowselector

	namespace cpulsecell_playsequence {

		constexpr std::uint32_t m_SequenceName{ 0x48 };
		constexpr std::uint32_t m_PulseAnimEvents{ 0x50 };
		constexpr std::uint32_t m_OnFinished{ 0x68 };
		constexpr std::uint32_t m_OnCanceled{ 0xB0 };

	} // namespace cpulsecell_playsequence

	namespace cpulsecell_playsequence__cursorstate_t {

		constexpr std::uint32_t m_hTarget{ 0x0 };

	} // namespace cpulsecell_playsequence__cursorstate_t

	namespace cpulsecell_step_callexternalmethod {

		constexpr std::uint32_t m_MethodName{ 0x48 };
		constexpr std::uint32_t m_GameBlackboard{ 0x58 };
		constexpr std::uint32_t m_ExpectedArgs{ 0x68 };
		constexpr std::uint32_t m_nAsyncCallMode{ 0x78 };
		constexpr std::uint32_t m_OnFinished{ 0x80 };

	} // namespace cpulsecell_step_callexternalmethod

	namespace cpulsecell_step_entfire {

		constexpr std::uint32_t m_Input{ 0x48 };

	} // namespace cpulsecell_step_entfire

	namespace cpulsecell_step_publicoutput {

		constexpr std::uint32_t m_OutputIndex{ 0x48 };

	} // namespace cpulsecell_step_publicoutput

	namespace cpulsecell_timeline {

		constexpr std::uint32_t m_TimelineEvents{ 0x48 };
		constexpr std::uint32_t m_bWaitForChildOutflows{ 0x60 };
		constexpr std::uint32_t m_OnFinished{ 0x68 };
		constexpr std::uint32_t m_OnCanceled{ 0xB0 };

	} // namespace cpulsecell_timeline

	namespace cpulsecell_timeline__timelineevent_t {

		constexpr std::uint32_t m_flTimeFromPrevious{ 0x0 };
		constexpr std::uint32_t m_EventOutflow{ 0x8 };

	} // namespace cpulsecell_timeline__timelineevent_t

	namespace cpulsecell_unknown {

		constexpr std::uint32_t m_UnknownKeys{ 0x48 };

	} // namespace cpulsecell_unknown

	namespace cpulsecell_value_curve {

		constexpr std::uint32_t m_Curve{ 0x48 };

	} // namespace cpulsecell_value_curve

	namespace cpulsecell_value_gradient {

		constexpr std::uint32_t m_Gradient{ 0x48 };

	} // namespace cpulsecell_value_gradient

	namespace cpulsecell_waitforcursorswithtag {

		constexpr std::uint32_t m_bTagSelfWhenComplete{ 0x98 };
		constexpr std::uint32_t m_nDesiredKillPriority{ 0x9C };

	} // namespace cpulsecell_waitforcursorswithtag

	namespace cpulsecell_waitforcursorswithtagbase {

		constexpr std::uint32_t m_nCursorsAllowedToWait{ 0x48 };
		constexpr std::uint32_t m_WaitComplete{ 0x50 };

	} // namespace cpulsecell_waitforcursorswithtagbase

	namespace cpulsecell_waitforcursorswithtagbase__cursorstate_t {

		constexpr std::uint32_t m_TagName{ 0x0 };

	} // namespace cpulsecell_waitforcursorswithtagbase__cursorstate_t

	namespace cpulsecell_waitforobservable {

		constexpr std::uint32_t m_Condition{ 0x48 };
		constexpr std::uint32_t m_OnTrue{ 0xC0 };

	} // namespace cpulsecell_waitforobservable

	namespace cpulsegameblackboard {

		constexpr std::uint32_t m_strGraphName{ 0x610 };
		constexpr std::uint32_t m_strStateBlob{ 0x618 };

	} // namespace cpulsegameblackboard

	namespace cpulsegraphdef {

		constexpr std::uint32_t m_DomainIdentifier{ 0x8 };
		constexpr std::uint32_t m_DomainSubType{ 0x18 };
		constexpr std::uint32_t m_ParentMapName{ 0x30 };
		constexpr std::uint32_t m_ParentXmlName{ 0x40 };
		constexpr std::uint32_t m_Chunks{ 0x50 };
		constexpr std::uint32_t m_Cells{ 0x68 };
		constexpr std::uint32_t m_Vars{ 0x80 };
		constexpr std::uint32_t m_PublicOutputs{ 0x98 };
		constexpr std::uint32_t m_InvokeBindings{ 0xB0 };
		constexpr std::uint32_t m_CallInfos{ 0xC8 };
		constexpr std::uint32_t m_Constants{ 0xE0 };
		constexpr std::uint32_t m_DomainValues{ 0xF8 };
		constexpr std::uint32_t m_BlackboardReferences{ 0x110 };
		constexpr std::uint32_t m_OutputConnections{ 0x128 };

	} // namespace cpulsegraphdef

	namespace cpulsegraphexecutionhistory {

		constexpr std::uint32_t m_nInstanceID{ 0x0 };
		constexpr std::uint32_t m_strFileName{ 0x8 };
		constexpr std::uint32_t m_vecHistory{ 0x10 };
		constexpr std::uint32_t m_mapCellDesc{ 0x28 };
		constexpr std::uint32_t m_mapCursorDesc{ 0x50 };

	} // namespace cpulsegraphexecutionhistory

	namespace cpulseruntimemethodarg {

		constexpr std::uint32_t m_Name{ 0x0 };
		constexpr std::uint32_t m_Description{ 0x38 };
		constexpr std::uint32_t m_Type{ 0x40 };

	} // namespace cpulseruntimemethodarg

	namespace cragdollmanager {

		constexpr std::uint32_t m_iCurrentMaxRagdollCount{ 0x608 };

	} // namespace cragdollmanager

	namespace crandsimtimer {

		constexpr std::uint32_t m_flMinInterval{ 0x8 };
		constexpr std::uint32_t m_flMaxInterval{ 0xC };

	} // namespace crandsimtimer

	namespace crandstopwatch {

		constexpr std::uint32_t m_flMinInterval{ 0xC };
		constexpr std::uint32_t m_flMaxInterval{ 0x10 };

	} // namespace crandstopwatch

	namespace crangefloat {

		constexpr std::uint32_t m_pValue{ 0x0 };

	} // namespace crangefloat

	namespace crangeint {

		constexpr std::uint32_t m_pValue{ 0x0 };

	} // namespace crangeint

	namespace cremapfloat {

		constexpr std::uint32_t m_pValue{ 0x0 };

	} // namespace cremapfloat

	namespace crendercomponent {

		constexpr std::uint32_t __m_pChainEntity{ 0x10 };
		constexpr std::uint32_t m_bIsRenderingWithViewModels{ 0x50 };
		constexpr std::uint32_t m_nSplitscreenFlags{ 0x54 };
		constexpr std::uint32_t m_bEnableRendering{ 0x58 };
		constexpr std::uint32_t m_bInterpolationReadyToDraw{ 0xA8 };

	} // namespace crendercomponent

	namespace cresponsecriteriaset {

		constexpr std::uint32_t m_nNumPrefixedContexts{ 0x30 };
		constexpr std::uint32_t m_bOverrideOnAppend{ 0x34 };

	} // namespace cresponsecriteriaset

	namespace cropeoverlaphit {

		constexpr std::uint32_t m_hEntity{ 0x0 };
		constexpr std::uint32_t m_vecOverlappingLinks{ 0x8 };

	} // namespace cropeoverlaphit

	namespace crr_response {

		constexpr std::uint32_t m_Type{ 0x0 };
		constexpr std::uint32_t m_szResponseName{ 0x1 };
		constexpr std::uint32_t m_szMatchingRule{ 0xC1 };
		constexpr std::uint32_t m_Params{ 0x160 };
		constexpr std::uint32_t m_fMatchScore{ 0x180 };
		constexpr std::uint32_t m_bAnyMatchingRulesInCooldown{ 0x184 };
		constexpr std::uint32_t m_szSpeakerContext{ 0x188 };
		constexpr std::uint32_t m_szWorldContext{ 0x190 };
		constexpr std::uint32_t m_Followup{ 0x198 };
		constexpr std::uint32_t m_recipientFilter{ 0x1CA };

	} // namespace crr_response

	namespace csceneeventinfo {

		constexpr std::uint32_t m_iLayer{ 0x0 };
		constexpr std::uint32_t m_iPriority{ 0x4 };
		constexpr std::uint32_t m_hSequence{ 0x8 };
		constexpr std::uint32_t m_flWeight{ 0xC };
		constexpr std::uint32_t m_hAnimClip{ 0x10 };
		constexpr std::uint32_t m_sAnimClipSlot{ 0x18 };
		constexpr std::uint32_t m_sAnimClipSlotWeight{ 0x20 };
		constexpr std::uint32_t m_bHasArrived{ 0x28 };
		constexpr std::uint32_t m_nType{ 0x2C };
		constexpr std::uint32_t m_flNext{ 0x30 };
		constexpr std::uint32_t m_bIsGesture{ 0x34 };
		constexpr std::uint32_t m_bShouldRemove{ 0x35 };
		constexpr std::uint32_t m_hTarget{ 0x5C };
		constexpr std::uint32_t m_nSceneEventId{ 0x60 };
		constexpr std::uint32_t m_bClientSide{ 0x64 };
		constexpr std::uint32_t m_bStarted{ 0x65 };

	} // namespace csceneeventinfo

	namespace cscriptcomponent {

		constexpr std::uint32_t m_scriptClassName{ 0x30 };

	} // namespace cscriptcomponent

	namespace cscriptuniformrandomstream {

		constexpr std::uint32_t m_hScriptScope{ 0x8 };
		constexpr std::uint32_t m_nInitialSeed{ 0x9C };

	} // namespace cscriptuniformrandomstream

	namespace csimplesimtimer {

		constexpr std::uint32_t m_flNext{ 0x0 };
		constexpr std::uint32_t m_nWorldGroupId{ 0x4 };

	} // namespace csimplesimtimer

	namespace csimtimer {

		constexpr std::uint32_t m_flInterval{ 0x8 };

	} // namespace csimtimer

	namespace cskeletonanimationcontroller {

		constexpr std::uint32_t m_pSkeletonInstance{ 0x8 };

	} // namespace cskeletonanimationcontroller

	namespace cskeletoninstance {

		constexpr std::uint32_t m_bDirtyMotionType{ 0x0 };
		constexpr std::uint32_t m_bIsGeneratingLatchedParentSpaceState{ 0x0 };
		constexpr std::uint32_t m_modelState{ 0x160 };
		constexpr std::uint32_t m_bIsAnimationEnabled{ 0x430 };
		constexpr std::uint32_t m_bUseParentRenderBounds{ 0x431 };
		constexpr std::uint32_t m_bDisableSolidCollisionsForHierarchy{ 0x432 };
		constexpr std::uint32_t m_materialGroup{ 0x434 };
		constexpr std::uint32_t m_nHitboxSet{ 0x438 };

	} // namespace cskeletoninstance

	namespace cskilldamage {

		constexpr std::uint32_t m_flDamage{ 0x0 };
		constexpr std::uint32_t m_flNPCDamageScalarVsNPC{ 0x10 };
		constexpr std::uint32_t m_flPhysicsForceDamage{ 0x14 };

	} // namespace cskilldamage

	namespace cskillfloat {

		constexpr std::uint32_t m_pValue{ 0x0 };

	} // namespace cskillfloat

	namespace cskillint {

		constexpr std::uint32_t m_pValue{ 0x0 };

	} // namespace cskillint

	namespace cskyboxreference {

		constexpr std::uint32_t m_worldGroupId{ 0x608 };
		constexpr std::uint32_t m_hSkyCamera{ 0x60C };

	} // namespace cskyboxreference

	namespace csmatchstats_t {

		constexpr std::uint32_t m_iEnemy5Ks{ 0x68 };
		constexpr std::uint32_t m_iEnemy4Ks{ 0x6C };
		constexpr std::uint32_t m_iEnemy3Ks{ 0x70 };
		constexpr std::uint32_t m_iEnemyKnifeKills{ 0x74 };
		constexpr std::uint32_t m_iEnemyTaserKills{ 0x78 };

	} // namespace csmatchstats_t

	namespace csoundenvelope {

		constexpr std::uint32_t m_current{ 0x0 };
		constexpr std::uint32_t m_target{ 0x4 };
		constexpr std::uint32_t m_rate{ 0x8 };
		constexpr std::uint32_t m_forceupdate{ 0xC };

	} // namespace csoundenvelope

	namespace csoundpatch {

		constexpr std::uint32_t m_pitch{ 0x8 };
		constexpr std::uint32_t m_volume{ 0x18 };
		constexpr std::uint32_t m_shutdownTime{ 0x3C };
		constexpr std::uint32_t m_flLastTime{ 0x40 };
		constexpr std::uint32_t m_iszSoundScriptName{ 0x48 };
		constexpr std::uint32_t m_hEnt{ 0x50 };
		constexpr std::uint32_t m_soundEntityIndex{ 0x54 };
		constexpr std::uint32_t m_soundOrigin{ 0x58 };
		constexpr std::uint32_t m_isPlaying{ 0x64 };
		constexpr std::uint32_t m_Filter{ 0x68 };
		constexpr std::uint32_t m_flCloseCaptionDuration{ 0xA0 };
		constexpr std::uint32_t m_bUpdatedSoundOrigin{ 0xA4 };
		constexpr std::uint32_t m_iszClassName{ 0xA8 };

	} // namespace csoundpatch

	namespace csperroundstats_t {

		constexpr std::uint32_t m_iKills{ 0x30 };
		constexpr std::uint32_t m_iDeaths{ 0x34 };
		constexpr std::uint32_t m_iAssists{ 0x38 };
		constexpr std::uint32_t m_iDamage{ 0x3C };
		constexpr std::uint32_t m_iEquipmentValue{ 0x40 };
		constexpr std::uint32_t m_iMoneySaved{ 0x44 };
		constexpr std::uint32_t m_iKillReward{ 0x48 };
		constexpr std::uint32_t m_iLiveTime{ 0x4C };
		constexpr std::uint32_t m_iHeadShotKills{ 0x50 };
		constexpr std::uint32_t m_iObjective{ 0x54 };
		constexpr std::uint32_t m_iCashEarned{ 0x58 };
		constexpr std::uint32_t m_iUtilityDamage{ 0x5C };
		constexpr std::uint32_t m_iEnemiesFlashed{ 0x60 };

	} // namespace csperroundstats_t

	namespace cstopwatch {

		constexpr std::uint32_t m_flInterval{ 0xC };

	} // namespace cstopwatch

	namespace cstopwatchbase {

		constexpr std::uint32_t m_fIsRunning{ 0x8 };

	} // namespace cstopwatchbase

	namespace ctakedamageinfo {

		constexpr std::uint32_t m_vecDamageForce{ 0x8 };
		constexpr std::uint32_t m_vecDamagePosition{ 0x14 };
		constexpr std::uint32_t m_vecReportedPosition{ 0x20 };
		constexpr std::uint32_t m_vecDamageDirection{ 0x2C };
		constexpr std::uint32_t m_hInflictor{ 0x38 };
		constexpr std::uint32_t m_hAttacker{ 0x3C };
		constexpr std::uint32_t m_hAbility{ 0x40 };
		constexpr std::uint32_t m_flDamage{ 0x44 };
		constexpr std::uint32_t m_flTotalledDamage{ 0x48 };
		constexpr std::uint32_t m_bitsDamageType{ 0x4C };
		constexpr std::uint32_t m_iDamageCustom{ 0x50 };
		constexpr std::uint32_t m_iAmmoType{ 0x54 };
		constexpr std::uint32_t m_flOriginalDamage{ 0x60 };
		constexpr std::uint32_t m_bShouldBleed{ 0x64 };
		constexpr std::uint32_t m_bShouldSpark{ 0x65 };
		constexpr std::uint32_t m_nDamageFlags{ 0x70 };
		constexpr std::uint32_t m_iHitGroupId{ 0x78 };
		constexpr std::uint32_t m_nNumObjectsPenetrated{ 0x7C };
		constexpr std::uint32_t m_flFriendlyFireDamageReductionRatio{ 0x80 };
		constexpr std::uint32_t m_bStoppedBullet{ 0x84 };
		constexpr std::uint32_t m_nDestructibleHitGroupsToForceDestroy{ 0x100 };
		constexpr std::uint32_t m_bInTakeDamageFlow{ 0x118 };

	} // namespace ctakedamageinfo

	namespace ctakedamageresult {

		constexpr std::uint32_t m_pOriginatingInfo{ 0x0 };
		constexpr std::uint32_t m_nHealthLost{ 0x8 };
		constexpr std::uint32_t m_nHealthBefore{ 0xC };
		constexpr std::uint32_t m_nDamageDealt{ 0x10 };
		constexpr std::uint32_t m_flPreModifiedDamage{ 0x14 };
		constexpr std::uint32_t m_nTotalledHealthLost{ 0x18 };
		constexpr std::uint32_t m_nTotalledDamageDealt{ 0x1C };
		constexpr std::uint32_t m_flTotalledPreModifiedDamage{ 0x20 };
		constexpr std::uint32_t m_bWasDamageSuppressed{ 0x24 };
		constexpr std::uint32_t m_bSuppressFlinch{ 0x25 };
		constexpr std::uint32_t m_nOverrideFlinchHitGroup{ 0x28 };

	} // namespace ctakedamageresult

	namespace ctakedamagesummaryscopeguard {

		constexpr std::uint32_t m_vecSummaries{ 0x8 };

	} // namespace ctakedamagesummaryscopeguard

	namespace ctimeline {

		constexpr std::uint32_t m_flValues{ 0x10 };
		constexpr std::uint32_t m_nValueCounts{ 0x110 };
		constexpr std::uint32_t m_nBucketCount{ 0x210 };
		constexpr std::uint32_t m_flInterval{ 0x214 };
		constexpr std::uint32_t m_flFinalValue{ 0x218 };
		constexpr std::uint32_t m_nCompressionType{ 0x21C };
		constexpr std::uint32_t m_bStopped{ 0x220 };

	} // namespace ctimeline

	namespace ctriggerfan {

		constexpr std::uint32_t m_vFanOriginOffset{ 0xF58 };
		constexpr std::uint32_t m_vDirection{ 0xF64 };
		constexpr std::uint32_t m_bPushTowardsInfoTarget{ 0xF70 };
		constexpr std::uint32_t m_bPushAwayFromInfoTarget{ 0xF71 };
		constexpr std::uint32_t m_qNoiseDelta{ 0xF80 };
		constexpr std::uint32_t m_hInfoFan{ 0xF90 };
		constexpr std::uint32_t m_flForce{ 0xF94 };
		constexpr std::uint32_t m_bFalloff{ 0xF98 };
		constexpr std::uint32_t m_RampTimer{ 0xFA0 };

	} // namespace ctriggerfan

	namespace cworldcompositionchunkreferenceelement_t {

		constexpr std::uint32_t m_strMapToLoad{ 0x0 };
		constexpr std::uint32_t m_strLandmarkName{ 0x8 };

	} // namespace cworldcompositionchunkreferenceelement_t

	namespace decalgroupoption_t {

		constexpr std::uint32_t m_hMaterial{ 0x0 };
		constexpr std::uint32_t m_sSequenceName{ 0x8 };
		constexpr std::uint32_t m_flProbability{ 0x10 };
		constexpr std::uint32_t m_bEnableAngleBetweenNormalAndGravityRange{ 0x14 };
		constexpr std::uint32_t m_flMinAngleBetweenNormalAndGravity{ 0x18 };
		constexpr std::uint32_t m_flMaxAngleBetweenNormalAndGravity{ 0x1C };

	} // namespace decalgroupoption_t

	namespace destructiblehitgrouptodestroy_t {

		constexpr std::uint32_t m_nHitGroup{ 0x0 };
		constexpr std::uint32_t m_nMaxDamageLevel{ 0x4 };

	} // namespace destructiblehitgrouptodestroy_t

	namespace destructiblepartdestructionrequest_t {

		constexpr std::uint32_t m_nDestroyFlags{ 0x0 };
		constexpr std::uint32_t m_nDamageType{ 0x4 };
		constexpr std::uint32_t m_flPartDamage{ 0x8 };
		constexpr std::uint32_t m_flPartDamageRadius{ 0xC };
		constexpr std::uint32_t m_vWsPartDamageOrigin{ 0x10 };
		constexpr std::uint32_t m_vWsPartDamageForce{ 0x1C };

	} // namespace destructiblepartdestructionrequest_t

	namespace enginecountdowntimer {

		constexpr std::uint32_t m_duration{ 0x8 };
		constexpr std::uint32_t m_timestamp{ 0xC };
		constexpr std::uint32_t m_timescale{ 0x10 };

	} // namespace enginecountdowntimer

	namespace engineloopstate_t {

		constexpr std::uint32_t m_nPlatWindowWidth{ 0x18 };
		constexpr std::uint32_t m_nPlatWindowHeight{ 0x1C };
		constexpr std::uint32_t m_nRenderWidth{ 0x20 };
		constexpr std::uint32_t m_nRenderHeight{ 0x24 };

	} // namespace engineloopstate_t

	namespace entcomponentinfo_t {

		constexpr std::uint32_t m_pName{ 0x0 };
		constexpr std::uint32_t m_pCPPClassname{ 0x8 };
		constexpr std::uint32_t m_pNetworkDataReferencedDescription{ 0x10 };
		constexpr std::uint32_t m_pNetworkDataReferencedPtrPropDescription{ 0x18 };
		constexpr std::uint32_t m_nRuntimeIndex{ 0x20 };
		constexpr std::uint32_t m_nFlags{ 0x24 };
		constexpr std::uint32_t m_pBaseClassComponentHelper{ 0x60 };

	} // namespace entcomponentinfo_t

	namespace entityrenderattribute_t {

		constexpr std::uint32_t m_ID{ 0x30 };
		constexpr std::uint32_t m_Values{ 0x34 };

	} // namespace entityrenderattribute_t

	namespace entityspottedstate_t {

		constexpr std::uint32_t m_bSpotted{ 0x8 };
		constexpr std::uint32_t m_bSpottedByMask{ 0xC };

	} // namespace entityspottedstate_t

	namespace eventadvancetick_t {

		constexpr std::uint32_t m_nCurrentTick{ 0x30 };
		constexpr std::uint32_t m_nCurrentTickThisFrame{ 0x34 };
		constexpr std::uint32_t m_nTotalTicksThisFrame{ 0x38 };
		constexpr std::uint32_t m_nTotalTicks{ 0x3C };

	} // namespace eventadvancetick_t

	namespace eventappshutdown_t {

		constexpr std::uint32_t m_nDummy0{ 0x0 };

	} // namespace eventappshutdown_t

	namespace eventclientframesimulate_t {

		constexpr std::uint32_t m_LoopState{ 0x0 };
		constexpr std::uint32_t m_flRealTime{ 0x28 };
		constexpr std::uint32_t m_flFrameTime{ 0x2C };
		constexpr std::uint32_t m_bScheduleSendTickPacket{ 0x30 };

	} // namespace eventclientframesimulate_t

	namespace eventclientoutput_t {

		constexpr std::uint32_t m_LoopState{ 0x0 };
		constexpr std::uint32_t m_flRenderTime{ 0x28 };
		constexpr std::uint32_t m_flRealTime{ 0x2C };
		constexpr std::uint32_t m_flRenderFrameTimeUnbounded{ 0x30 };
		constexpr std::uint32_t m_bRenderOnly{ 0x34 };

	} // namespace eventclientoutput_t

	namespace eventclientpollinput_t {

		constexpr std::uint32_t m_LoopState{ 0x0 };
		constexpr std::uint32_t m_flRealTime{ 0x28 };

	} // namespace eventclientpollinput_t

	namespace eventclientpollnetworking_t {

		constexpr std::uint32_t m_nTickCount{ 0x0 };

	} // namespace eventclientpollnetworking_t

	namespace eventclientpostoutput_t {

		constexpr std::uint32_t m_LoopState{ 0x0 };
		constexpr std::uint32_t m_flRenderTime{ 0x28 };
		constexpr std::uint32_t m_flRenderFrameTime{ 0x30 };
		constexpr std::uint32_t m_flRenderFrameTimeUnbounded{ 0x34 };
		constexpr std::uint32_t m_bRenderOnly{ 0x38 };

	} // namespace eventclientpostoutput_t

	namespace eventclientpreoutput_t {

		constexpr std::uint32_t m_LoopState{ 0x0 };
		constexpr std::uint32_t m_flRenderTime{ 0x28 };
		constexpr std::uint32_t m_flRenderFrameTime{ 0x30 };
		constexpr std::uint32_t m_flRenderFrameTimeUnbounded{ 0x38 };
		constexpr std::uint32_t m_flRealTime{ 0x40 };
		constexpr std::uint32_t m_bRenderOnly{ 0x44 };

	} // namespace eventclientpreoutput_t

	namespace eventclientprocessgameinput_t {

		constexpr std::uint32_t m_LoopState{ 0x0 };
		constexpr std::uint32_t m_flRealTime{ 0x28 };
		constexpr std::uint32_t m_flFrameTime{ 0x2C };

	} // namespace eventclientprocessgameinput_t

	namespace eventclientprocessinput_t {

		constexpr std::uint32_t m_LoopState{ 0x0 };
		constexpr std::uint32_t m_flRealTime{ 0x28 };
		constexpr std::uint32_t m_flTickInterval{ 0x2C };
		constexpr std::uint32_t m_flTickStartTime{ 0x30 };

	} // namespace eventclientprocessinput_t

	namespace eventclientprocessnetworking_t {

		constexpr std::uint32_t m_nTickCount{ 0x0 };

	} // namespace eventclientprocessnetworking_t

	namespace eventclientscenesystemthreadstatechange_t {

		constexpr std::uint32_t m_bThreadsActive{ 0x0 };

	} // namespace eventclientscenesystemthreadstatechange_t

	namespace eventframeboundary_t {

		constexpr std::uint32_t m_flFrameTime{ 0x0 };

	} // namespace eventframeboundary_t

	namespace eventpostadvancetick_t {

		constexpr std::uint32_t m_nCurrentTick{ 0x30 };
		constexpr std::uint32_t m_nCurrentTickThisFrame{ 0x34 };
		constexpr std::uint32_t m_nTotalTicksThisFrame{ 0x38 };
		constexpr std::uint32_t m_nTotalTicks{ 0x3C };

	} // namespace eventpostadvancetick_t

	namespace eventpostdataupdate_t {

		constexpr std::uint32_t m_nCount{ 0x0 };

	} // namespace eventpostdataupdate_t

	namespace eventpredataupdate_t {

		constexpr std::uint32_t m_nCount{ 0x0 };

	} // namespace eventpredataupdate_t

	namespace eventprofilestorageavailable_t {

		constexpr std::uint32_t m_nSplitScreenSlot{ 0x0 };

	} // namespace eventprofilestorageavailable_t

	namespace eventserverbeginasyncposttickwork_t {

		constexpr std::uint32_t m_bIsOncePerFrameAsyncWorkPhase{ 0x0 };

	} // namespace eventserverbeginasyncposttickwork_t

	namespace eventserverendsimulate_t {

		constexpr std::uint32_t m_bLastTick{ 0x0 };

	} // namespace eventserverendsimulate_t

	namespace eventserverpostadvancetick_t {

		constexpr std::uint32_t m_bLastTickBeforeClientUpdate{ 0x40 };

	} // namespace eventserverpostadvancetick_t

	namespace eventserverpostsimulate_t {

		constexpr std::uint32_t m_bLastTickBeforeClientUpdate{ 0x30 };

	} // namespace eventserverpostsimulate_t

	namespace eventsettime_t {

		constexpr std::uint32_t m_LoopState{ 0x0 };
		constexpr std::uint32_t m_nClientOutputFrames{ 0x28 };
		constexpr std::uint32_t m_flRealTime{ 0x30 };
		constexpr std::uint32_t m_flRenderTime{ 0x38 };
		constexpr std::uint32_t m_flRenderFrameTime{ 0x40 };
		constexpr std::uint32_t m_flRenderFrameTimeUnbounded{ 0x48 };
		constexpr std::uint32_t m_flRenderFrameTimeUnscaled{ 0x50 };
		constexpr std::uint32_t m_flTickRemainder{ 0x58 };

	} // namespace eventsettime_t

	namespace eventsimpleloopframeupdate_t {

		constexpr std::uint32_t m_LoopState{ 0x0 };
		constexpr std::uint32_t m_flRealTime{ 0x28 };
		constexpr std::uint32_t m_flFrameTime{ 0x2C };

	} // namespace eventsimpleloopframeupdate_t

	namespace eventsimulate_t {

		constexpr std::uint32_t m_LoopState{ 0x0 };
		constexpr std::uint32_t m_bFirstTick{ 0x28 };
		constexpr std::uint32_t m_bLastTick{ 0x29 };

	} // namespace eventsimulate_t

	namespace externalanimgraph_t {

		constexpr std::uint32_t m_hExtGraphHandle{ 0x0 };
		constexpr std::uint32_t m_sExternalGraphSlotID{ 0x8 };
		constexpr std::uint32_t m_hGraphDefinition{ 0x10 };
		constexpr std::uint32_t m_hExternalGraphOwner{ 0x18 };
		constexpr std::uint32_t m_nInactiveBehavior{ 0x30 };

	} // namespace externalanimgraph_t

	namespace externalanimgraphhandle_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace externalanimgraphhandle_t

	namespace filterdamagetype {

		constexpr std::uint32_t m_iDamageType{ 0x640 };

	} // namespace filterdamagetype

	namespace filterhealth {

		constexpr std::uint32_t m_bAdrenalineActive{ 0x640 };
		constexpr std::uint32_t m_iHealthMin{ 0x644 };
		constexpr std::uint32_t m_iHealthMax{ 0x648 };

	} // namespace filterhealth

	namespace fogparams_t {

		constexpr std::uint32_t dirPrimary{ 0x8 };
		constexpr std::uint32_t colorPrimary{ 0x14 };
		constexpr std::uint32_t colorSecondary{ 0x18 };
		constexpr std::uint32_t colorPrimaryLerpTo{ 0x1C };
		constexpr std::uint32_t colorSecondaryLerpTo{ 0x20 };
		constexpr std::uint32_t start{ 0x24 };
		constexpr std::uint32_t end{ 0x28 };
		constexpr std::uint32_t farz{ 0x2C };
		constexpr std::uint32_t maxdensity{ 0x30 };
		constexpr std::uint32_t exponent{ 0x34 };
		constexpr std::uint32_t HDRColorScale{ 0x38 };
		constexpr std::uint32_t skyboxFogFactor{ 0x3C };
		constexpr std::uint32_t skyboxFogFactorLerpTo{ 0x40 };
		constexpr std::uint32_t startLerpTo{ 0x44 };
		constexpr std::uint32_t endLerpTo{ 0x48 };
		constexpr std::uint32_t maxdensityLerpTo{ 0x4C };
		constexpr std::uint32_t lerptime{ 0x50 };
		constexpr std::uint32_t duration{ 0x54 };
		constexpr std::uint32_t blendtobackground{ 0x58 };
		constexpr std::uint32_t scattering{ 0x5C };
		constexpr std::uint32_t locallightscale{ 0x60 };
		constexpr std::uint32_t enable{ 0x64 };
		constexpr std::uint32_t blend{ 0x65 };
		constexpr std::uint32_t m_bPadding2{ 0x66 };
		constexpr std::uint32_t m_bPadding{ 0x67 };

	} // namespace fogparams_t

	namespace fourquaternions {

		constexpr std::uint32_t x{ 0x0 };
		constexpr std::uint32_t y{ 0x10 };
		constexpr std::uint32_t z{ 0x20 };
		constexpr std::uint32_t w{ 0x30 };

	} // namespace fourquaternions

	namespace functioninfo_t {

		constexpr std::uint32_t m_name{ 0x8 };
		constexpr std::uint32_t m_nameToken{ 0x10 };
		constexpr std::uint32_t m_nParamCount{ 0x14 };
		constexpr std::uint32_t m_nIndex{ 0x18 };
		constexpr std::uint32_t m_bIsPure{ 0x1A };

	} // namespace functioninfo_t

	namespace fusefunctionindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace fusefunctionindex_t

	namespace fusevariableindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace fusevariableindex_t

	namespace gameammotypeinfo_t {

		constexpr std::uint32_t m_nBuySize{ 0x38 };
		constexpr std::uint32_t m_nCost{ 0x3C };

	} // namespace gameammotypeinfo_t

	namespace gametick_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace gametick_t

	namespace gametime_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace gametime_t

	namespace generatedtexturehandle_t {

		constexpr std::uint32_t m_strBitmapName{ 0x0 };

	} // namespace generatedtexturehandle_t

	namespace hudtextparms_t {

		constexpr std::uint32_t color1{ 0x0 };
		constexpr std::uint32_t color2{ 0x4 };
		constexpr std::uint32_t effect{ 0x8 };
		constexpr std::uint32_t channel{ 0x9 };
		constexpr std::uint32_t x{ 0xC };
		constexpr std::uint32_t y{ 0x10 };

	} // namespace hudtextparms_t

	namespace hullflags_t {

		constexpr std::uint32_t m_bHull_Human{ 0x0 };
		constexpr std::uint32_t m_bHull_SmallCentered{ 0x1 };
		constexpr std::uint32_t m_bHull_WideHuman{ 0x2 };
		constexpr std::uint32_t m_bHull_Tiny{ 0x3 };
		constexpr std::uint32_t m_bHull_Medium{ 0x4 };
		constexpr std::uint32_t m_bHull_TinyCentered{ 0x5 };
		constexpr std::uint32_t m_bHull_Large{ 0x6 };
		constexpr std::uint32_t m_bHull_LargeCentered{ 0x7 };
		constexpr std::uint32_t m_bHull_MediumTall{ 0x8 };
		constexpr std::uint32_t m_bHull_Small{ 0x9 };

	} // namespace hullflags_t

	namespace intervaltimer {

		constexpr std::uint32_t m_timestamp{ 0x8 };
		constexpr std::uint32_t m_nWorldGroupId{ 0xC };

	} // namespace intervaltimer

	namespace inv_image_camera_t {

		constexpr std::uint32_t angle{ 0x0 };
		constexpr std::uint32_t fov{ 0xC };
		constexpr std::uint32_t znear{ 0x10 };
		constexpr std::uint32_t zfar{ 0x14 };
		constexpr std::uint32_t target{ 0x18 };
		constexpr std::uint32_t target_nudge{ 0x24 };
		constexpr std::uint32_t orbit_distance{ 0x30 };

	} // namespace inv_image_camera_t

	namespace inv_image_clearcolor_t {

		constexpr std::uint32_t color{ 0x0 };

	} // namespace inv_image_clearcolor_t

	namespace inv_image_data_t {

		constexpr std::uint32_t map{ 0x0 };
		constexpr std::uint32_t item{ 0x10 };
		constexpr std::uint32_t camera{ 0x30 };
		constexpr std::uint32_t lightsun{ 0x64 };
		constexpr std::uint32_t lightfill{ 0x80 };
		constexpr std::uint32_t light0{ 0x9C };
		constexpr std::uint32_t light1{ 0xBC };
		constexpr std::uint32_t clearcolor{ 0xDC };

	} // namespace inv_image_data_t

	namespace inv_image_item_t {

		constexpr std::uint32_t position{ 0x0 };
		constexpr std::uint32_t angle{ 0xC };
		constexpr std::uint32_t pose_sequence{ 0x18 };

	} // namespace inv_image_item_t

	namespace inv_image_light_barn_t {

		constexpr std::uint32_t color{ 0x0 };
		constexpr std::uint32_t angle{ 0xC };
		constexpr std::uint32_t brightness{ 0x18 };
		constexpr std::uint32_t orbit_distance{ 0x1C };

	} // namespace inv_image_light_barn_t

	namespace inv_image_light_fill_t {

		constexpr std::uint32_t color{ 0x0 };
		constexpr std::uint32_t angle{ 0xC };
		constexpr std::uint32_t brightness{ 0x18 };

	} // namespace inv_image_light_fill_t

	namespace inv_image_light_sun_t {

		constexpr std::uint32_t color{ 0x0 };
		constexpr std::uint32_t angle{ 0xC };
		constexpr std::uint32_t brightness{ 0x18 };

	} // namespace inv_image_light_sun_t

	namespace inv_image_map_t {

		constexpr std::uint32_t map_name{ 0x0 };
		constexpr std::uint32_t map_rotation{ 0x8 };

	} // namespace inv_image_map_t

	namespace modelconfighandle_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace modelconfighandle_t

	namespace nmbonemasksetdefinition_t {

		constexpr std::uint32_t m_ID{ 0x0 };
		constexpr std::uint32_t m_primaryWeightList{ 0x8 };
		constexpr std::uint32_t m_secondaryWeightLists{ 0x118 };

	} // namespace nmbonemasksetdefinition_t

	namespace nmcompressionsettings_t {

		constexpr std::uint32_t m_translationRangeX{ 0x0 };
		constexpr std::uint32_t m_translationRangeY{ 0x8 };
		constexpr std::uint32_t m_translationRangeZ{ 0x10 };
		constexpr std::uint32_t m_scaleRange{ 0x18 };
		constexpr std::uint32_t m_constantRotation{ 0x20 };
		constexpr std::uint32_t m_bIsRotationStatic{ 0x30 };
		constexpr std::uint32_t m_bIsTranslationStatic{ 0x31 };
		constexpr std::uint32_t m_bIsScaleStatic{ 0x32 };

	} // namespace nmcompressionsettings_t

	namespace nmcompressionsettings_t__quantizationrange_t {

		constexpr std::uint32_t m_flRangeStart{ 0x0 };
		constexpr std::uint32_t m_flRangeLength{ 0x4 };

	} // namespace nmcompressionsettings_t__quantizationrange_t

	namespace nmfloatcurvecompressionsettings_t {

		constexpr std::uint32_t m_range{ 0x0 };
		constexpr std::uint32_t m_bIsStatic{ 0x8 };

	} // namespace nmfloatcurvecompressionsettings_t

	namespace nmpercent_t {

		constexpr std::uint32_t m_flValue{ 0x0 };

	} // namespace nmpercent_t

	namespace nmsynctracktime_t {

		constexpr std::uint32_t m_nEventIdx{ 0x0 };
		constexpr std::uint32_t m_percentageThrough{ 0x4 };

	} // namespace nmsynctracktime_t

	namespace nmsynctracktimerange_t {

		constexpr std::uint32_t m_startTime{ 0x0 };
		constexpr std::uint32_t m_endTime{ 0x8 };

	} // namespace nmsynctracktimerange_t

	namespace outflowwithrequirements_t {

		constexpr std::uint32_t m_Connection{ 0x0 };
		constexpr std::uint32_t m_DestinationFlowNodeID{ 0x48 };
		constexpr std::uint32_t m_RequirementNodeIDs{ 0x50 };
		constexpr std::uint32_t m_nCursorStateBlockIndex{ 0x68 };

	} // namespace outflowwithrequirements_t

	namespace packedaabb_t {

		constexpr std::uint32_t m_nPackedMin{ 0x0 };
		constexpr std::uint32_t m_nPackedMax{ 0x4 };

	} // namespace packedaabb_t

	namespace particleindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace particleindex_t

	namespace particlenode_t {

		constexpr std::uint32_t m_hEntity{ 0x0 };
		constexpr std::uint32_t m_iIndex{ 0x4 };
		constexpr std::uint32_t m_flStartTime{ 0x8 };
		constexpr std::uint32_t m_flGrowthDuration{ 0xC };
		constexpr std::uint32_t m_vecGrowthOrigin{ 0x10 };
		constexpr std::uint32_t m_flEndcapTime{ 0x1C };
		constexpr std::uint32_t m_bMarkedForDelete{ 0x20 };

	} // namespace particlenode_t

	namespace pgdinstruction_t {

		constexpr std::uint32_t m_nCode{ 0x0 };
		constexpr std::uint32_t m_nVar{ 0x4 };
		constexpr std::uint32_t m_nReg0{ 0x8 };
		constexpr std::uint32_t m_nReg1{ 0xA };
		constexpr std::uint32_t m_nReg2{ 0xC };
		constexpr std::uint32_t m_nInvokeBindingIndex{ 0x10 };
		constexpr std::uint32_t m_nChunk{ 0x14 };
		constexpr std::uint32_t m_nDestInstruction{ 0x18 };
		constexpr std::uint32_t m_nCallInfoIndex{ 0x1C };
		constexpr std::uint32_t m_nConstIdx{ 0x20 };
		constexpr std::uint32_t m_nDomainValueIdx{ 0x22 };
		constexpr std::uint32_t m_nBlackboardReferenceIdx{ 0x24 };

	} // namespace pgdinstruction_t

	namespace physicsparticleid_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace physicsparticleid_t

	namespace physicsragdollpose_t {

		constexpr std::uint32_t m_Transforms{ 0x8 };
		constexpr std::uint32_t m_hOwner{ 0x20 };
		constexpr std::uint32_t m_bSetFromDebugHistory{ 0x24 };

	} // namespace physicsragdollpose_t

	namespace pointcamerasettings_t {

		constexpr std::uint32_t m_flNearBlurryDistance{ 0x0 };
		constexpr std::uint32_t m_flNearCrispDistance{ 0x4 };
		constexpr std::uint32_t m_flFarCrispDistance{ 0x8 };
		constexpr std::uint32_t m_flFarBlurryDistance{ 0xC };

	} // namespace pointcamerasettings_t

	namespace predicteddamagetag_t {

		constexpr std::uint32_t nTagTick{ 0x30 };
		constexpr std::uint32_t flFlinchModSmall{ 0x34 };
		constexpr std::uint32_t flFlinchModLarge{ 0x38 };
		constexpr std::uint32_t flFriendlyFireDamageReductionRatio{ 0x3C };

	} // namespace predicteddamagetag_t

	namespace pulsecursorid_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulsecursorid_t

	namespace pulsecursoryieldtoken_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulsecursoryieldtoken_t

	namespace pulsedocnodeid_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulsedocnodeid_t

	namespace pulsegraphexecutionhistorycursordesc_t {

		constexpr std::uint32_t vecAncestorCursorIDs{ 0x0 };
		constexpr std::uint32_t nSpawnNodeID{ 0x18 };
		constexpr std::uint32_t nRetiredAtNodeID{ 0x1C };
		constexpr std::uint32_t flLastReferenced{ 0x20 };
		constexpr std::uint32_t nLastValidEntryIdx{ 0x24 };

	} // namespace pulsegraphexecutionhistorycursordesc_t

	namespace pulsegraphexecutionhistoryentry_t {

		constexpr std::uint32_t nCursorID{ 0x0 };
		constexpr std::uint32_t nEditorID{ 0x4 };
		constexpr std::uint32_t flExecTime{ 0x8 };
		constexpr std::uint32_t unFlags{ 0xC };
		constexpr std::uint32_t tagName{ 0x10 };

	} // namespace pulsegraphexecutionhistoryentry_t

	namespace pulsegraphexecutionhistorynodedesc_t {

		constexpr std::uint32_t strCellDesc{ 0x0 };
		constexpr std::uint32_t strBindingName{ 0x10 };

	} // namespace pulsegraphexecutionhistorynodedesc_t

	namespace pulsegraphinstanceid_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulsegraphinstanceid_t

	namespace pulsenodedynamicoutflows_t {

		constexpr std::uint32_t m_Outflows{ 0x0 };

	} // namespace pulsenodedynamicoutflows_t

	namespace pulsenodedynamicoutflows_t__dynamicoutflow_t {

		constexpr std::uint32_t m_OutflowID{ 0x0 };
		constexpr std::uint32_t m_Connection{ 0x8 };

	} // namespace pulsenodedynamicoutflows_t__dynamicoutflow_t

	namespace pulseobservableboolexpression_t {

		constexpr std::uint32_t m_EvaluateConnection{ 0x0 };
		constexpr std::uint32_t m_DependentObservableVars{ 0x48 };
		constexpr std::uint32_t m_DependentObservableBlackboardReferences{ 0x60 };

	} // namespace pulseobservableboolexpression_t

	namespace pulseregistermap_t {

		constexpr std::uint32_t m_Inparams{ 0x0 };
		constexpr std::uint32_t m_InparamsWhichCanBeMoved{ 0x10 };
		constexpr std::uint32_t m_Outparams{ 0x20 };

	} // namespace pulseregistermap_t

	namespace pulseruntimeblackboardreferenceindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimeblackboardreferenceindex_t

	namespace pulseruntimecallinfoindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimecallinfoindex_t

	namespace pulseruntimecellindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimecellindex_t

	namespace pulseruntimechunkindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimechunkindex_t

	namespace pulseruntimeconstantindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimeconstantindex_t

	namespace pulseruntimedomainvalueindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimedomainvalueindex_t

	namespace pulseruntimeentrypointindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimeentrypointindex_t

	namespace pulseruntimeinvokeindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimeinvokeindex_t

	namespace pulseruntimeoutputindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimeoutputindex_t

	namespace pulseruntimeregisterindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimeregisterindex_t

	namespace pulseruntimestateoffset_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimestateoffset_t

	namespace pulseruntimevarindex_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace pulseruntimevarindex_t

	namespace pulseselectoroutflowlist_t {

		constexpr std::uint32_t m_Outflows{ 0x0 };

	} // namespace pulseselectoroutflowlist_t

	namespace ragdoll_t {

		constexpr std::uint32_t list{ 0x0 };
		constexpr std::uint32_t hierarchyJoints{ 0x18 };
		constexpr std::uint32_t boneIndex{ 0x30 };
		constexpr std::uint32_t allowStretch{ 0x48 };
		constexpr std::uint32_t unused{ 0x49 };

	} // namespace ragdoll_t

	namespace ragdollcreationparams_t {

		constexpr std::uint32_t m_vForce{ 0x0 };
		constexpr std::uint32_t m_nForceBone{ 0xC };
		constexpr std::uint32_t m_bForceCurrentWorldTransform{ 0x10 };
		constexpr std::uint32_t m_bUseLRURetirement{ 0x11 };
		constexpr std::uint32_t m_nHealthToGrant{ 0x14 };

	} // namespace ragdollcreationparams_t

	namespace ragdollelement_t {

		constexpr std::uint32_t originParentSpace{ 0x0 };
		constexpr std::uint32_t parentIndex{ 0x20 };
		constexpr std::uint32_t m_flRadius{ 0x24 };
		constexpr std::uint32_t m_nHeight{ 0x28 };

	} // namespace ragdollelement_t

	namespace ragdollhierarchyjoint_t {

		constexpr std::uint32_t parentIndex{ 0x0 };
		constexpr std::uint32_t childIndex{ 0x4 };

	} // namespace ragdollhierarchyjoint_t

	namespace responsefollowup {

		constexpr std::uint32_t followup_concept{ 0x0 };
		constexpr std::uint32_t followup_contexts{ 0x8 };
		constexpr std::uint32_t followup_delay{ 0x10 };
		constexpr std::uint32_t followup_target{ 0x14 };
		constexpr std::uint32_t followup_entityiotarget{ 0x1C };
		constexpr std::uint32_t followup_entityioinput{ 0x24 };
		constexpr std::uint32_t followup_entityiodelay{ 0x2C };
		constexpr std::uint32_t bFired{ 0x30 };

	} // namespace responsefollowup

	namespace responseparams {

		constexpr std::uint32_t odds{ 0x10 };
		constexpr std::uint32_t flags{ 0x12 };
		constexpr std::uint32_t m_pFollowup{ 0x18 };

	} // namespace responseparams

	namespace sceneeventid_t {

		constexpr std::uint32_t m_Value{ 0x0 };

	} // namespace sceneeventid_t

	namespace sellbackpurchaseentry_t {

		constexpr std::uint32_t m_unDefIdx{ 0x30 };
		constexpr std::uint32_t m_nCost{ 0x34 };
		constexpr std::uint32_t m_nPrevArmor{ 0x38 };
		constexpr std::uint32_t m_bPrevHelmet{ 0x3C };
		constexpr std::uint32_t m_hItem{ 0x40 };

	} // namespace sellbackpurchaseentry_t

	namespace sequencehistory_t {

		constexpr std::uint32_t m_hSequence{ 0x0 };
		constexpr std::uint32_t m_flSeqStartTime{ 0x4 };
		constexpr std::uint32_t m_flSeqFixedCycle{ 0x8 };
		constexpr std::uint32_t m_nSeqLoopMode{ 0xC };
		constexpr std::uint32_t m_flPlaybackRate{ 0x10 };
		constexpr std::uint32_t m_flCyclesPerSecond{ 0x14 };

	} // namespace sequencehistory_t

	namespace serverauthoritativeweaponslot_t {

		constexpr std::uint32_t unClass{ 0x30 };
		constexpr std::uint32_t unSlot{ 0x32 };
		constexpr std::uint32_t unItemDefIdx{ 0x34 };

	} // namespace serverauthoritativeweaponslot_t

	namespace shard_model_desc_t {

		constexpr std::uint32_t m_nModelID{ 0x8 };
		constexpr std::uint32_t m_hMaterialBase{ 0x10 };
		constexpr std::uint32_t m_hMaterialDamageOverlay{ 0x18 };
		constexpr std::uint32_t m_solid{ 0x20 };
		constexpr std::uint32_t m_vecPanelSize{ 0x24 };
		constexpr std::uint32_t m_vecStressPositionA{ 0x2C };
		constexpr std::uint32_t m_vecStressPositionB{ 0x34 };
		constexpr std::uint32_t m_vecPanelVertices{ 0x40 };
		constexpr std::uint32_t m_vInitialPanelVertices{ 0x58 };
		constexpr std::uint32_t m_flGlassHalfThickness{ 0x70 };
		constexpr std::uint32_t m_bHasParent{ 0x74 };
		constexpr std::uint32_t m_bParentFrozen{ 0x75 };
		constexpr std::uint32_t m_SurfacePropStringToken{ 0x78 };

	} // namespace shard_model_desc_t

	namespace sky3dparams_t {

		constexpr std::uint32_t scale{ 0x8 };
		constexpr std::uint32_t origin{ 0xC };
		constexpr std::uint32_t bClip3DSkyBoxNearToWorldFar{ 0x18 };
		constexpr std::uint32_t flClip3DSkyBoxNearToWorldFarOffset{ 0x1C };
		constexpr std::uint32_t fog{ 0x20 };
		constexpr std::uint32_t m_nWorldGroupID{ 0x88 };

	} // namespace sky3dparams_t

	namespace sndopvarlatchdata_t {

		constexpr std::uint32_t m_iszStack{ 0x8 };
		constexpr std::uint32_t m_iszOperator{ 0x10 };
		constexpr std::uint32_t m_iszOpvar{ 0x18 };
		constexpr std::uint32_t m_flVal{ 0x20 };
		constexpr std::uint32_t m_vPos{ 0x24 };

	} // namespace sndopvarlatchdata_t

	namespace soundeventpathcornerpairnetworked_t {

		constexpr std::uint32_t vP1{ 0x0 };
		constexpr std::uint32_t vP2{ 0xC };
		constexpr std::uint32_t flPathLengthSqr{ 0x18 };
		constexpr std::uint32_t flP1Pct{ 0x1C };
		constexpr std::uint32_t flP2Pct{ 0x20 };

	} // namespace soundeventpathcornerpairnetworked_t

	namespace summarytakedamageinfo_t {

		constexpr std::uint32_t nSummarisedCount{ 0x0 };
		constexpr std::uint32_t info{ 0x8 };
		constexpr std::uint32_t result{ 0x128 };
		constexpr std::uint32_t hTarget{ 0x158 };

	} // namespace summarytakedamageinfo_t

	namespace thinkfunc_t {

		constexpr std::uint32_t m_hFn{ 0x8 };
		constexpr std::uint32_t m_nContext{ 0x10 };
		constexpr std::uint32_t m_nNextThinkTick{ 0x14 };
		constexpr std::uint32_t m_nLastThinkTick{ 0x18 };

	} // namespace thinkfunc_t

	namespace timedevent {

		constexpr std::uint32_t m_TimeBetweenEvents{ 0x0 };
		constexpr std::uint32_t m_fNextEvent{ 0x4 };

	} // namespace timedevent

	namespace variableinfo_t {

		constexpr std::uint32_t m_name{ 0x0 };
		constexpr std::uint32_t m_nameToken{ 0x8 };
		constexpr std::uint32_t m_nIndex{ 0xC };
		constexpr std::uint32_t m_nNumComponents{ 0xE };
		constexpr std::uint32_t m_eVarType{ 0xF };
		constexpr std::uint32_t m_eAccess{ 0x10 };

	} // namespace variableinfo_t

	namespace viewangleserverchange_t {

		constexpr std::uint32_t nType{ 0x30 };
		constexpr std::uint32_t qAngle{ 0x34 };
		constexpr std::uint32_t nIndex{ 0x40 };

	} // namespace viewangleserverchange_t

	namespace vphysicscollisionattribute_t {

		constexpr std::uint32_t m_nInteractsAs{ 0x8 };
		constexpr std::uint32_t m_nInteractsWith{ 0x10 };
		constexpr std::uint32_t m_nInteractsExclude{ 0x18 };
		constexpr std::uint32_t m_nEntityId{ 0x20 };
		constexpr std::uint32_t m_nOwnerId{ 0x24 };
		constexpr std::uint32_t m_nHierarchyId{ 0x28 };
		constexpr std::uint32_t m_nDetailLayerMask{ 0x2A };
		constexpr std::uint32_t m_nDetailLayerMaskType{ 0x2C };
		constexpr std::uint32_t m_nTargetDetailLayer{ 0x2D };
		constexpr std::uint32_t m_nCollisionGroup{ 0x2E };
		constexpr std::uint32_t m_nCollisionFunctionMask{ 0x2F };

	} // namespace vphysicscollisionattribute_t

	namespace waterwheeldrag_t {

		constexpr std::uint32_t m_flFractionOfWheelSubmerged{ 0x0 };
		constexpr std::uint32_t m_flWheelDrag{ 0x4 };

	} // namespace waterwheeldrag_t

	namespace waterwheelfrictionscale_t {

		constexpr std::uint32_t m_flFractionOfWheelSubmerged{ 0x0 };
		constexpr std::uint32_t m_flFrictionScale{ 0x4 };

	} // namespace waterwheelfrictionscale_t

	namespace weaponpurchasecount_t {

		constexpr std::uint32_t m_nItemDefIndex{ 0x30 };
		constexpr std::uint32_t m_nCount{ 0x32 };

	} // namespace weaponpurchasecount_t

	namespace weaponpurchasetracker_t {

		constexpr std::uint32_t m_weaponPurchases{ 0x8 };

	} // namespace weaponpurchasetracker_t

} // namespace opaline::sdk::offsets::client
