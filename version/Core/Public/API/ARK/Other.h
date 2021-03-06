#pragma once

#include "API/Enums.h"

struct FDamageEvent
{
	float& ImpulseField() { return *GetNativePointerField<float*>(this, "FDamageEvent.Impulse"); }
	float& OriginalDamageField() { return *GetNativePointerField<float*>(this, "FDamageEvent.OriginalDamage"); }
	int& InstanceBodyIndexField() { return *GetNativePointerField<int*>(this, "FDamageEvent.InstanceBodyIndex"); }
	TSubclassOf<UDamageType>& DamageTypeClassField() { return *GetNativePointerField<TSubclassOf<UDamageType>*>(this, "FDamageEvent.DamageTypeClass"); }

	// Functions

	void GetBestHitInfo(AActor * HitActor, AActor * HitInstigator, FHitResult * OutHitInfo, FVector * OutImpulseDir) { NativeCall<void, AActor *, AActor *, FHitResult *, FVector *>(this, "FDamageEvent.GetBestHitInfo", HitActor, HitInstigator, OutHitInfo, OutImpulseDir); }
	static UScriptStruct * StaticStruct() { return NativeCall<UScriptStruct *>(nullptr, "FDamageEvent.StaticStruct"); }
};

struct UPhysicalMaterial
{
};
struct FBodyInstance
{
};

struct __declspec(align(8)) FHitResult
{
	unsigned __int32 bBlockingHit : 1;
	unsigned __int32 bStartPenetrating : 1;
	unsigned __int32 bVolatileCollision : 1;
	float Time;
	FVector_NetQuantize Location;
	FVector_NetQuantizeNormal Normal;
	FVector_NetQuantize ImpactPoint;
	FVector_NetQuantizeNormal ImpactNormal;
	FVector_NetQuantize TraceStart;
	FVector_NetQuantize TraceEnd;
	float PenetrationDepth;
	int Item;
	TWeakObjectPtr<UPhysicalMaterial> PhysMaterial;
	TWeakObjectPtr<AActor> Actor;
	TWeakObjectPtr<UPrimitiveComponent> Component;
	FBodyInstance *BodyInstance;
	FName BoneName;
	int FaceIndex;

	// Functions

	void operator=(FHitResult * __that) { NativeCall<void, FHitResult *>(this, "FHitResult.operator=", __that); }
	AActor * GetActor() { return NativeCall<AActor *>(this, "FHitResult.GetActor"); }
	UPrimitiveComponent * GetComponent() { return NativeCall<UPrimitiveComponent *>(this, "FHitResult.GetComponent"); }
	static UScriptStruct * StaticStruct() { return NativeCall<UScriptStruct *>(nullptr, "FHitResult.StaticStruct"); }
};

struct FOverlapInfo
{
	bool bFromSweep;
	FHitResult OverlapInfo;
	void *CachedCompPtr;
};

struct FInternetAddr
{
};

struct FSocket
{
	ESocketType& SocketTypeField() { return *GetNativePointerField<ESocketType*>(this, "FSocket.SocketType"); }
	FString& SocketDescriptionField() { return *GetNativePointerField<FString*>(this, "FSocket.SocketDescription"); }

};

struct FSocketBSD : FSocket
{
	unsigned __int64& SocketField() { return *GetNativePointerField<unsigned __int64*>(this, "FSocketBSD.Socket"); }
	FDateTime& LastActivityTimeField() { return *GetNativePointerField<FDateTime*>(this, "FSocketBSD.LastActivityTime"); }

	// Functions

	bool Close() { return NativeCall<bool>(this, "FSocketBSD.Close"); }
	bool Bind(FInternetAddr * Addr) { return NativeCall<bool, FInternetAddr *>(this, "FSocketBSD.Bind", Addr); }
	bool Connect(FInternetAddr * Addr) { return NativeCall<bool, FInternetAddr *>(this, "FSocketBSD.Connect", Addr); }
	bool Listen(int MaxBacklog) { return NativeCall<bool, int>(this, "FSocketBSD.Listen", MaxBacklog); }
	bool HasPendingConnection(bool * bHasPendingConnection) { return NativeCall<bool, bool *>(this, "FSocketBSD.HasPendingConnection", bHasPendingConnection); }
	bool HasPendingData(unsigned int * PendingDataSize) { return NativeCall<bool, unsigned int *>(this, "FSocketBSD.HasPendingData", PendingDataSize); }
	FSocket * Accept(FString * SocketDescription) { return NativeCall<FSocket *, FString *>(this, "FSocketBSD.Accept", SocketDescription); }
	FSocket * Accept(FInternetAddr * OutAddr, FString * SocketDescription) { return NativeCall<FSocket *, FInternetAddr *, FString *>(this, "FSocketBSD.Accept", OutAddr, SocketDescription); }
	bool SendTo(const char * Data, int Count, int * BytesSent, FInternetAddr * Destination) { return NativeCall<bool, const char *, int, int *, FInternetAddr *>(this, "FSocketBSD.SendTo", Data, Count, BytesSent, Destination); }
	bool Send(const char * Data, int Count, int * BytesSent) { return NativeCall<bool, const char *, int, int *>(this, "FSocketBSD.Send", Data, Count, BytesSent); }
	bool RecvFrom(char * Data, int BufferSize, int * BytesRead, FInternetAddr * Source, ESocketReceiveFlags::Type Flags) { return NativeCall<bool, char *, int, int *, FInternetAddr *, ESocketReceiveFlags::Type>(this, "FSocketBSD.RecvFrom", Data, BufferSize, BytesRead, Source, Flags); }
	bool Recv(char * Data, int BufferSize, int * BytesRead, ESocketReceiveFlags::Type Flags) { return NativeCall<bool, char *, int, int *, ESocketReceiveFlags::Type>(this, "FSocketBSD.Recv", Data, BufferSize, BytesRead, Flags); }
	ESocketConnectionState GetConnectionState() { return NativeCall<ESocketConnectionState>(this, "FSocketBSD.GetConnectionState"); }
	void GetAddress(FInternetAddr * OutAddr) { NativeCall<void, FInternetAddr *>(this, "FSocketBSD.GetAddress", OutAddr); }
	bool SetNonBlocking(bool bIsNonBlocking) { return NativeCall<bool, bool>(this, "FSocketBSD.SetNonBlocking", bIsNonBlocking); }
	bool SetBroadcast(bool bAllowBroadcast) { return NativeCall<bool, bool>(this, "FSocketBSD.SetBroadcast", bAllowBroadcast); }
	bool JoinMulticastGroup(FInternetAddr * GroupAddress) { return NativeCall<bool, FInternetAddr *>(this, "FSocketBSD.JoinMulticastGroup", GroupAddress); }
	bool LeaveMulticastGroup(FInternetAddr * GroupAddress) { return NativeCall<bool, FInternetAddr *>(this, "FSocketBSD.LeaveMulticastGroup", GroupAddress); }
	bool SetMulticastLoopback(bool bLoopback) { return NativeCall<bool, bool>(this, "FSocketBSD.SetMulticastLoopback", bLoopback); }
	bool SetMulticastTtl(char TimeToLive) { return NativeCall<bool, char>(this, "FSocketBSD.SetMulticastTtl", TimeToLive); }
	bool SetReuseAddr(bool bAllowReuse) { return NativeCall<bool, bool>(this, "FSocketBSD.SetReuseAddr", bAllowReuse); }
	bool SetLinger(bool bShouldLinger, int Timeout) { return NativeCall<bool, bool, int>(this, "FSocketBSD.SetLinger", bShouldLinger, Timeout); }
	bool SetSendBufferSize(int Size, int * NewSize) { return NativeCall<bool, int, int *>(this, "FSocketBSD.SetSendBufferSize", Size, NewSize); }
	bool SetReceiveBufferSize(int Size, int * NewSize) { return NativeCall<bool, int, int *>(this, "FSocketBSD.SetReceiveBufferSize", Size, NewSize); }
	int GetPortNo() { return NativeCall<int>(this, "FSocketBSD.GetPortNo"); }
};

struct RCONClientConnection
{
	FSocket * SocketField() { return *GetNativePointerField<FSocket **>(this, "RCONClientConnection.Socket"); }
	UShooterCheatManager * CheatManagerField() { return *GetNativePointerField<UShooterCheatManager **>(this, "RCONClientConnection.CheatManager"); }
	bool& IsAuthenticatedField() { return *GetNativePointerField<bool*>(this, "RCONClientConnection.IsAuthenticated"); }
	bool& IsClosedField() { return *GetNativePointerField<bool*>(this, "RCONClientConnection.IsClosed"); }
	TArray<signed char>& DataBufferField() { return *GetNativePointerField<TArray<signed char>*>(this, "RCONClientConnection.DataBuffer"); }
	unsigned int& CurrentPacketSizeField() { return *GetNativePointerField<unsigned int*>(this, "RCONClientConnection.CurrentPacketSize"); }
	long double& LastReceiveTimeField() { return *GetNativePointerField<long double*>(this, "RCONClientConnection.LastReceiveTime"); }
	long double& LastSendKeepAliveTimeField() { return *GetNativePointerField<long double*>(this, "RCONClientConnection.LastSendKeepAliveTime"); }
	FString& ServerPasswordField() { return *GetNativePointerField<FString*>(this, "RCONClientConnection.ServerPassword"); }

	// Functions

	void Tick(long double WorldTime, UWorld * InWorld) { NativeCall<void, long double, UWorld *>(this, "RCONClientConnection.Tick", WorldTime, InWorld); }
	void ProcessRCONPacket(RCONPacket * Packet, UWorld * InWorld) { NativeCall<void, RCONPacket *, UWorld *>(this, "RCONClientConnection.ProcessRCONPacket", Packet, InWorld); }
	void SendMessageW(int Id, int Type, FString * OutGoingMessage) { NativeCall<void, int, int, FString *>(this, "RCONClientConnection.SendMessageW", Id, Type, OutGoingMessage); }
	void Close() { NativeCall<void>(this, "RCONClientConnection.Close"); }
};

struct RCONPacket
{
	int Length;
	int Id;
	int Type;
	FString Body;
};

struct UGameplayStatics
{
	static APlayerController * GetPlayerController(UObject * WorldContextObject, int PlayerIndex) { return NativeCall<APlayerController *, UObject *, int>(nullptr, "UGameplayStatics.GetPlayerController", WorldContextObject, PlayerIndex); }
	static APlayerController * CreatePlayer(UObject * WorldContextObject, int ControllerId, bool bSpawnPawn) { return NativeCall<APlayerController *, UObject *, int, bool>(nullptr, "UGameplayStatics.CreatePlayer", WorldContextObject, ControllerId, bSpawnPawn); }
	static void SetGlobalTimeDilation(UObject * WorldContextObject, float TimeDilation) { NativeCall<void, UObject *, float>(nullptr, "UGameplayStatics.SetGlobalTimeDilation", WorldContextObject, TimeDilation); }
	static bool SetGamePaused(UObject * WorldContextObject, bool bPaused) { return NativeCall<bool, UObject *, bool>(nullptr, "UGameplayStatics.SetGamePaused", WorldContextObject, bPaused); }
	static bool ApplyRadialDamage(UObject * WorldContextObject, float BaseDamage, FVector * Origin, float DamageRadius, TSubclassOf<UDamageType> DamageTypeClass, TArray<AActor *> * IgnoreActors, AActor * DamageCauser, AController * InstigatedByController, bool bDoFullDamage, ECollisionChannel DamagePreventionChannel, float Impulse) { return NativeCall<bool, UObject *, float, FVector *, float, TSubclassOf<UDamageType>, TArray<AActor *> *, AActor *, AController *, bool, ECollisionChannel, float>(nullptr, "UGameplayStatics.ApplyRadialDamage", WorldContextObject, BaseDamage, Origin, DamageRadius, DamageTypeClass, IgnoreActors, DamageCauser, InstigatedByController, bDoFullDamage, DamagePreventionChannel, Impulse); }
	static bool ApplyRadialDamageIgnoreDamageActors(UObject * WorldContextObject, float BaseDamage, FVector * Origin, float DamageRadius, TSubclassOf<UDamageType> DamageTypeClass, TArray<AActor *> * IgnoreActors, TArray<AActor *> * IgnoreDamageActors, AActor * DamageCauser, AController * InstigatedByController, bool bDoFullDamage, ECollisionChannel DamagePreventionChannel, float Impulse) { return NativeCall<bool, UObject *, float, FVector *, float, TSubclassOf<UDamageType>, TArray<AActor *> *, TArray<AActor *> *, AActor *, AController *, bool, ECollisionChannel, float>(nullptr, "UGameplayStatics.ApplyRadialDamageIgnoreDamageActors", WorldContextObject, BaseDamage, Origin, DamageRadius, DamageTypeClass, IgnoreActors, IgnoreDamageActors, DamageCauser, InstigatedByController, bDoFullDamage, DamagePreventionChannel, Impulse); }
	static bool ApplyRadialDamageWithFalloff(UObject * WorldContextObject, float BaseDamage, float MinimumDamage, FVector * Origin, float DamageInnerRadius, float DamageOuterRadius, float DamageFalloff, TSubclassOf<UDamageType> DamageTypeClass, TArray<AActor *> * IgnoreActors, AActor * DamageCauser, AController * InstigatedByController, ECollisionChannel DamagePreventionChannel, float Impulse, TArray<AActor *> * IgnoreDamageActors, int NumAdditionalAttempts) { return NativeCall<bool, UObject *, float, float, FVector *, float, float, float, TSubclassOf<UDamageType>, TArray<AActor *> *, AActor *, AController *, ECollisionChannel, float, TArray<AActor *> *, int>(nullptr, "UGameplayStatics.ApplyRadialDamageWithFalloff", WorldContextObject, BaseDamage, MinimumDamage, Origin, DamageInnerRadius, DamageOuterRadius, DamageFalloff, DamageTypeClass, IgnoreActors, DamageCauser, InstigatedByController, DamagePreventionChannel, Impulse, IgnoreDamageActors, NumAdditionalAttempts); }
	static void ApplyPointDamage(AActor * DamagedActor, float BaseDamage, FVector * HitFromDirection, FHitResult * HitInfo, AController * EventInstigator, AActor * DamageCauser, TSubclassOf<UDamageType> DamageTypeClass, float Impulse, bool bForceCollisionCheck, ECollisionChannel ForceCollisionCheckTraceChannel) { NativeCall<void, AActor *, float, FVector *, FHitResult *, AController *, AActor *, TSubclassOf<UDamageType>, float, bool, ECollisionChannel>(nullptr, "UGameplayStatics.ApplyPointDamage", DamagedActor, BaseDamage, HitFromDirection, HitInfo, EventInstigator, DamageCauser, DamageTypeClass, Impulse, bForceCollisionCheck, ForceCollisionCheckTraceChannel); }
	static void ApplyDamage(AActor * DamagedActor, float BaseDamage, AController * EventInstigator, AActor * DamageCauser, TSubclassOf<UDamageType> DamageTypeClass, float Impulse) { NativeCall<void, AActor *, float, AController *, AActor *, TSubclassOf<UDamageType>, float>(nullptr, "UGameplayStatics.ApplyDamage", DamagedActor, BaseDamage, EventInstigator, DamageCauser, DamageTypeClass, Impulse); }
	static AActor * BeginSpawningActorFromBlueprint(UObject * WorldContextObject, UBlueprint * Blueprint, FTransform * SpawnTransform, bool bNoCollisionFail) { return NativeCall<AActor *, UObject *, UBlueprint *, FTransform *, bool>(nullptr, "UGameplayStatics.BeginSpawningActorFromBlueprint", WorldContextObject, Blueprint, SpawnTransform, bNoCollisionFail); }
	static AActor * BeginSpawningActorFromClass(UObject * WorldContextObject, TSubclassOf<AActor> ActorClass, FTransform * SpawnTransform, bool bNoCollisionFail) { return NativeCall<AActor *, UObject *, TSubclassOf<AActor>, FTransform *, bool>(nullptr, "UGameplayStatics.BeginSpawningActorFromClass", WorldContextObject, ActorClass, SpawnTransform, bNoCollisionFail); }
	static void OpenLevel(UObject * WorldContextObject, FName LevelName, bool bAbsolute, FString Options) { NativeCall<void, UObject *, FName, bool, FString>(nullptr, "UGameplayStatics.OpenLevel", WorldContextObject, LevelName, bAbsolute, Options); }
	static FVector * GetActorArrayAverageLocation(FVector * result, TArray<AActor *> * Actors) { return NativeCall<FVector *, FVector *, TArray<AActor *> *>(nullptr, "UGameplayStatics.GetActorArrayAverageLocation", result, Actors); }
	static void GetActorArrayBounds(TArray<AActor *> * Actors, bool bOnlyCollidingComponents, FVector * Center, FVector * BoxExtent) { NativeCall<void, TArray<AActor *> *, bool, FVector *, FVector *>(nullptr, "UGameplayStatics.GetActorArrayBounds", Actors, bOnlyCollidingComponents, Center, BoxExtent); }
	static void GetAllActorsOfClass(UObject * WorldContextObject, TSubclassOf<AActor> ActorClass, TArray<AActor *> * OutActors) { NativeCall<void, UObject *, TSubclassOf<AActor>, TArray<AActor *> *>(nullptr, "UGameplayStatics.GetAllActorsOfClass", WorldContextObject, ActorClass, OutActors); }
	//static void GetAllActorsWithInterface(UObject * WorldContextObject, TSubclassOf<UInterface> Interface, TArray<AActor *> * OutActors) { NativeCall<void, UObject *, TSubclassOf<UInterface>, TArray<AActor *> *>(nullptr, "UGameplayStatics.GetAllActorsWithInterface", WorldContextObject, Interface, OutActors); }
	static EPhysicalSurface GetSurfaceType(FHitResult * Hit) { return NativeCall<EPhysicalSurface, FHitResult *>(nullptr, "UGameplayStatics.GetSurfaceType", Hit); }
	static bool AreAnyListenersWithinRange(FVector Location, float MaximumRange) { return NativeCall<bool, FVector, float>(nullptr, "UGameplayStatics.AreAnyListenersWithinRange", Location, MaximumRange); }
	static void PlaySound(UObject * WorldContextObject, USoundCue * InSoundCue, USceneComponent * AttachComponent, FName AttachName, bool bFollow, float VolumeMultiplier, float PitchMultiplier) { NativeCall<void, UObject *, USoundCue *, USceneComponent *, FName, bool, float, float>(nullptr, "UGameplayStatics.PlaySound", WorldContextObject, InSoundCue, AttachComponent, AttachName, bFollow, VolumeMultiplier, PitchMultiplier); }
	static void GetAccurateRealTime(UObject * WorldContextObject, int * Seconds, float * PartialSeconds) { NativeCall<void, UObject *, int *, float *>(nullptr, "UGameplayStatics.GetAccurateRealTime", WorldContextObject, Seconds, PartialSeconds); }
};

struct FItemMultiplier
{
	TSubclassOf<UPrimalItem> ItemClass;
	float ItemMultiplier;
};

struct APrimalBuff
{
	float& DeactivationLifespanField() { return *GetNativePointerField<float*>(this, "APrimalBuff.DeactivationLifespan"); }
	FName& InstigatorAttachmentSocketField() { return *GetNativePointerField<FName*>(this, "APrimalBuff.InstigatorAttachmentSocket"); }
	float& RemoteForcedFleeDurationField() { return *GetNativePointerField<float*>(this, "APrimalBuff.RemoteForcedFleeDuration"); }
	FVector& AoETraceToTargetsStartOffsetField() { return *GetNativePointerField<FVector*>(this, "APrimalBuff.AoETraceToTargetsStartOffset"); }
	TWeakObjectPtr<AActor>& TargetField() { return *GetNativePointerField<TWeakObjectPtr<AActor>*>(this, "APrimalBuff.Target"); }
	TWeakObjectPtr<UPrimalItem>& InstigatorItemField() { return *GetNativePointerField<TWeakObjectPtr<UPrimalItem>*>(this, "APrimalBuff.InstigatorItem"); }
	float& SlowInstigatorFallingAddZVelocityField() { return *GetNativePointerField<float*>(this, "APrimalBuff.SlowInstigatorFallingAddZVelocity"); }
	float& SlowInstigatorFallingDampenZVelocityField() { return *GetNativePointerField<float*>(this, "APrimalBuff.SlowInstigatorFallingDampenZVelocity"); }
	float& DeactivateAfterTimeField() { return *GetNativePointerField<float*>(this, "APrimalBuff.DeactivateAfterTime"); }
	float& WeaponRecoilMultiplierField() { return *GetNativePointerField<float*>(this, "APrimalBuff.WeaponRecoilMultiplier"); }
	float& ReceiveDamageMultiplierField() { return *GetNativePointerField<float*>(this, "APrimalBuff.ReceiveDamageMultiplier"); }
	float& MeleeDamageMultiplierField() { return *GetNativePointerField<float*>(this, "APrimalBuff.MeleeDamageMultiplier"); }
	float& DepleteInstigatorItemDurabilityPerSecondField() { return *GetNativePointerField<float*>(this, "APrimalBuff.DepleteInstigatorItemDurabilityPerSecond"); }
	FieldArray<float, 12> ValuesToAddPerSecondField() { return { this, "APrimalBuff.ValuesToAddPerSecond" }; }
	float& CharacterAdd_DefaultHyperthermicInsulationField() { return *GetNativePointerField<float*>(this, "APrimalBuff.CharacterAdd_DefaultHyperthermicInsulation"); }
	float& CharacterAdd_DefaultHypothermicInsulationField() { return *GetNativePointerField<float*>(this, "APrimalBuff.CharacterAdd_DefaultHypothermicInsulation"); }
	float& CharacterMultiplier_ExtraWaterConsumptionMultiplierField() { return *GetNativePointerField<float*>(this, "APrimalBuff.CharacterMultiplier_ExtraWaterConsumptionMultiplier"); }
	float& CharacterMultiplier_ExtraFoodConsumptionMultiplierField() { return *GetNativePointerField<float*>(this, "APrimalBuff.CharacterMultiplier_ExtraFoodConsumptionMultiplier"); }
	float& CharacterMultiplier_SubmergedOxygenDecreaseSpeedField() { return *GetNativePointerField<float*>(this, "APrimalBuff.CharacterMultiplier_SubmergedOxygenDecreaseSpeed"); }
	float& ViewMinExposureMultiplierField() { return *GetNativePointerField<float*>(this, "APrimalBuff.ViewMinExposureMultiplier"); }
	float& ViewMaxExposureMultiplierField() { return *GetNativePointerField<float*>(this, "APrimalBuff.ViewMaxExposureMultiplier"); }
	float& XPtoAddField() { return *GetNativePointerField<float*>(this, "APrimalBuff.XPtoAdd"); }
	float& XPtoAddRateField() { return *GetNativePointerField<float*>(this, "APrimalBuff.XPtoAddRate"); }
	bool& bDeactivateAfterAddingXPField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bDeactivateAfterAddingXP"); }
	float& SubmergedMaxSpeedModifierField() { return *GetNativePointerField<float*>(this, "APrimalBuff.SubmergedMaxSpeedModifier"); }
	float& UnsubmergedMaxSpeedModifierField() { return *GetNativePointerField<float*>(this, "APrimalBuff.UnsubmergedMaxSpeedModifier"); }
	long double& BuffStartTimeField() { return *GetNativePointerField<long double*>(this, "APrimalBuff.BuffStartTime"); }
	UMaterialInterface * BuffPostProcessEffectField() { return *GetNativePointerField<UMaterialInterface **>(this, "APrimalBuff.BuffPostProcessEffect"); }
	TArray<TSubclassOf<AActor>>& PreventActorClassesTargetingField() { return *GetNativePointerField<TArray<TSubclassOf<AActor>>*>(this, "APrimalBuff.PreventActorClassesTargeting"); }
	TArray<float>& PreventActorClassesTargetingRangesField() { return *GetNativePointerField<TArray<float>*>(this, "APrimalBuff.PreventActorClassesTargetingRanges"); }
	TSubclassOf<APrimalBuff>& AOEOtherBuffToApplyField() { return *GetNativePointerField<TSubclassOf<APrimalBuff>*>(this, "APrimalBuff.AOEOtherBuffToApply"); }
	float& AOEBuffRangeField() { return *GetNativePointerField<float*>(this, "APrimalBuff.AOEBuffRange"); }
	float& CharacterAOEBuffDamageField() { return *GetNativePointerField<float*>(this, "APrimalBuff.CharacterAOEBuffDamage"); }
	float& CharacterAOEBuffResistanceField() { return *GetNativePointerField<float*>(this, "APrimalBuff.CharacterAOEBuffResistance"); }
	float& Maximum2DVelocityForStaminaRecoveryField() { return *GetNativePointerField<float*>(this, "APrimalBuff.Maximum2DVelocityForStaminaRecovery"); }
	TArray<UMaterialInterface *> PostprocessBlendablesToExcludeField() { return *GetNativePointerField<TArray<UMaterialInterface *>*>(this, "APrimalBuff.PostprocessBlendablesToExclude"); }
	TArray<TWeakObjectPtr<APrimalCharacter>>& BuffedCharactersField() { return *GetNativePointerField<TArray<TWeakObjectPtr<APrimalCharacter>>*>(this, "APrimalBuff.BuffedCharacters"); }
	long double& LastItemDurabilityDepletionTimeField() { return *GetNativePointerField<long double*>(this, "APrimalBuff.LastItemDurabilityDepletionTime"); }
	TSubclassOf<APrimalBuff>& BuffToGiveOnDeactivationField() { return *GetNativePointerField<TSubclassOf<APrimalBuff>*>(this, "APrimalBuff.BuffToGiveOnDeactivation"); }
	TArray<TSubclassOf<APrimalBuff>>& BuffClassesToCancelOnActivationField() { return *GetNativePointerField<TArray<TSubclassOf<APrimalBuff>>*>(this, "APrimalBuff.BuffClassesToCancelOnActivation"); }
	TArray<TSubclassOf<APrimalBuff>>& ActivePreventsBuffClassesField() { return *GetNativePointerField<TArray<TSubclassOf<APrimalBuff>>*>(this, "APrimalBuff.ActivePreventsBuffClasses"); }
	TArray<TSubclassOf<APrimalCharacter>>& BuffRequiresOwnerClassField() { return *GetNativePointerField<TArray<TSubclassOf<APrimalCharacter>>*>(this, "APrimalBuff.BuffRequiresOwnerClass"); }
	TArray<TSubclassOf<APrimalCharacter>>& BuffPreventsOwnerClassField() { return *GetNativePointerField<TArray<TSubclassOf<APrimalCharacter>>*>(this, "APrimalBuff.BuffPreventsOwnerClass"); }
	float& XPEarningMultiplierField() { return *GetNativePointerField<float*>(this, "APrimalBuff.XPEarningMultiplier"); }
	bool& bUseBPSetupForInstigatorField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bUseBPSetupForInstigator"); }
	bool& bUseBPDeactivatedField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bUseBPDeactivated"); }
	bool& bUseBPCustomAllowAddBuffField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bUseBPCustomAllowAddBuff"); }
	FVector& staticPathingDestinationField() { return *GetNativePointerField<FVector*>(this, "APrimalBuff.staticPathingDestination"); }
	long double& TickingDeactivationTimeField() { return *GetNativePointerField<long double*>(this, "APrimalBuff.TickingDeactivationTime"); }
	UPrimalBuffPersistentData * MyBuffPersistentDataField() { return *GetNativePointerField<UPrimalBuffPersistentData **>(this, "APrimalBuff.MyBuffPersistentData"); }
	TSubclassOf<UPrimalBuffPersistentData>& BuffPersistentDataClassField() { return *GetNativePointerField<TSubclassOf<UPrimalBuffPersistentData>*>(this, "APrimalBuff.BuffPersistentDataClass"); }
	TWeakObjectPtr<AActor>& DamageCauserField() { return *GetNativePointerField<TWeakObjectPtr<AActor>*>(this, "APrimalBuff.DamageCauser"); }
	USoundBase * ExtraActivationSoundToPlayField() { return *GetNativePointerField<USoundBase **>(this, "APrimalBuff.ExtraActivationSoundToPlay"); }
	bool& bPersistentBuffSurvivesLevelUpField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bPersistentBuffSurvivesLevelUp"); }
	float& AoEApplyDamageField() { return *GetNativePointerField<float*>(this, "APrimalBuff.AoEApplyDamage"); }
	float& AoEApplyDamageIntervalField() { return *GetNativePointerField<float*>(this, "APrimalBuff.AoEApplyDamageInterval"); }
	TSubclassOf<UDamageType>& AoEApplyDamageTypeField() { return *GetNativePointerField<TSubclassOf<UDamageType>*>(this, "APrimalBuff.AoEApplyDamageType"); }
	TSubclassOf<APrimalBuff>& ForceNetworkSpatializationMaxLimitBuffTypeField() { return *GetNativePointerField<TSubclassOf<APrimalBuff>*>(this, "APrimalBuff.ForceNetworkSpatializationMaxLimitBuffType"); }
	int& ForceNetworkSpatializationBuffMaxLimitNumField() { return *GetNativePointerField<int*>(this, "APrimalBuff.ForceNetworkSpatializationBuffMaxLimitNum"); }
	float& ForceNetworkSpatializationBuffMaxLimitRangeField() { return *GetNativePointerField<float*>(this, "APrimalBuff.ForceNetworkSpatializationBuffMaxLimitRange"); }
	float& InsulationRangeField() { return *GetNativePointerField<float*>(this, "APrimalBuff.InsulationRange"); }
	float& HyperThermiaInsulationField() { return *GetNativePointerField<float*>(this, "APrimalBuff.HyperThermiaInsulation"); }
	float& HypoThermiaInsulationField() { return *GetNativePointerField<float*>(this, "APrimalBuff.HypoThermiaInsulation"); }
	FVector& AoEBuffLocOffsetField() { return *GetNativePointerField<FVector*>(this, "APrimalBuff.AoEBuffLocOffset"); }
	TArray<TSubclassOf<AActor>>& AoEClassesToIncludeField() { return *GetNativePointerField<TArray<TSubclassOf<AActor>>*>(this, "APrimalBuff.AoEClassesToInclude"); }
	TArray<TSubclassOf<AActor>>& AoEClassesToExcludeField() { return *GetNativePointerField<TArray<TSubclassOf<AActor>>*>(this, "APrimalBuff.AoEClassesToExclude"); }
	bool& bUseBPExcludeAoEActorField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bUseBPExcludeAoEActor"); }
	bool& bOverrideBuffDescriptionField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bOverrideBuffDescription"); }
	bool& bOnlyTickWhenPossessedField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bOnlyTickWhenPossessed"); }
	bool& bDestroyWhenUnpossessedField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bDestroyWhenUnpossessed"); }
	long double& LastAoEApplyDamageTimeField() { return *GetNativePointerField<long double*>(this, "APrimalBuff.LastAoEApplyDamageTime"); }
	float& OnlyForInstigatorSoundFadeInTimeField() { return *GetNativePointerField<float*>(this, "APrimalBuff.OnlyForInstigatorSoundFadeInTime"); }
	bool& bUseBuffTickServerField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bUseBuffTickServer"); }
	bool& bUseBuffTickClientField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bUseBuffTickClient"); }
	float& BuffTickServerMaxTimeField() { return *GetNativePointerField<float*>(this, "APrimalBuff.BuffTickServerMaxTime"); }
	float& BuffTickServerMinTimeField() { return *GetNativePointerField<float*>(this, "APrimalBuff.BuffTickServerMinTime"); }
	float& BuffTickClientMaxTimeField() { return *GetNativePointerField<float*>(this, "APrimalBuff.BuffTickClientMaxTime"); }
	float& BuffTickClientMinTimeField() { return *GetNativePointerField<float*>(this, "APrimalBuff.BuffTickClientMinTime"); }
	long double& LastBuffTickTimeServerField() { return *GetNativePointerField<long double*>(this, "APrimalBuff.LastBuffTickTimeServer"); }
	long double& LastBuffTickTimeClientField() { return *GetNativePointerField<long double*>(this, "APrimalBuff.LastBuffTickTimeClient"); }
	long double& NextBuffTickTimeServerField() { return *GetNativePointerField<long double*>(this, "APrimalBuff.NextBuffTickTimeServer"); }
	long double& NextBuffTickTimeClientField() { return *GetNativePointerField<long double*>(this, "APrimalBuff.NextBuffTickTimeClient"); }
	bool& bTickFunctionDisabledField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bTickFunctionDisabled"); }
	bool& bWasStasisedField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bWasStasised"); }
	int& AddBuffMaxNumStacksField() { return *GetNativePointerField<int*>(this, "APrimalBuff.AddBuffMaxNumStacks"); }
	USoundBase * DeactivatedSoundField() { return *GetNativePointerField<USoundBase **>(this, "APrimalBuff.DeactivatedSound"); }
	bool& bDeactivatedSoundOnlyLocalField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bDeactivatedSoundOnlyLocal"); }
	bool& bDisableBloomField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bDisableBloom"); }
	bool& bBPOverrideCharacterNewFallVelocityField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bBPOverrideCharacterNewFallVelocity"); }
	bool& bBPModifyCharacterFOVField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bBPModifyCharacterFOV"); }
	bool& bDisableLightShaftsField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bDisableLightShafts"); }
	float& PostProcessInterpSpeedDownField() { return *GetNativePointerField<float*>(this, "APrimalBuff.PostProcessInterpSpeedDown"); }
	float& PostProcessInterpSpeedUpField() { return *GetNativePointerField<float*>(this, "APrimalBuff.PostProcessInterpSpeedUp"); }
	float& TPVCameraSpeedInterpolationMultiplierField() { return *GetNativePointerField<float*>(this, "APrimalBuff.TPVCameraSpeedInterpolationMultiplier"); }
	bool& bIsCarryBuffField() { return *GetNativePointerField<bool*>(this, "APrimalBuff.bIsCarryBuff"); }
	long double& TimeForNextAOECheckField() { return *GetNativePointerField<long double*>(this, "APrimalBuff.TimeForNextAOECheck"); }
	float& AOEBuffIntervalMinField() { return *GetNativePointerField<float*>(this, "APrimalBuff.AOEBuffIntervalMin"); }
	float& AOEBuffIntervalMaxField() { return *GetNativePointerField<float*>(this, "APrimalBuff.AOEBuffIntervalMax"); }
	float& MaximumVelocityZForSlowingFallField() { return *GetNativePointerField<float*>(this, "APrimalBuff.MaximumVelocityZForSlowingFall"); }
	int& FNameIntField() { return *GetNativePointerField<int*>(this, "APrimalBuff.FNameInt"); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bSlowInstigatorFalling() { return { this, "APrimalBuff.bSlowInstigatorFalling" }; }
	BitFieldValue<bool, unsigned __int32> bDeactivateOnJump() { return { this, "APrimalBuff.bDeactivateOnJump" }; }
	BitFieldValue<bool, unsigned __int32> bPreventJump() { return { this, "APrimalBuff.bPreventJump" }; }
	BitFieldValue<bool, unsigned __int32> bDeactivated() { return { this, "APrimalBuff.bDeactivated" }; }
	BitFieldValue<bool, unsigned __int32> bUsesInstigator() { return { this, "APrimalBuff.bUsesInstigator" }; }
	BitFieldValue<bool, unsigned __int32> bFollowTarget() { return { this, "APrimalBuff.bFollowTarget" }; }
	BitFieldValue<bool, unsigned __int32> bAddCharacterValues() { return { this, "APrimalBuff.bAddCharacterValues" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyAddCharacterValuesUnderwater() { return { this, "APrimalBuff.bOnlyAddCharacterValuesUnderwater" }; }
	BitFieldValue<bool, unsigned __int32> bDisableIfCharacterUnderwater() { return { this, "APrimalBuff.bDisableIfCharacterUnderwater" }; }
	BitFieldValue<bool, unsigned __int32> bUseInstigatorItem() { return { this, "APrimalBuff.bUseInstigatorItem" }; }
	BitFieldValue<bool, unsigned __int32> bDestroyOnTargetStasis() { return { this, "APrimalBuff.bDestroyOnTargetStasis" }; }
	BitFieldValue<bool, unsigned __int32> bAoETraceToTargets() { return { this, "APrimalBuff.bAoETraceToTargets" }; }
	BitFieldValue<bool, unsigned __int32> bAOEOnlyApplyOtherBuffToWildDinos() { return { this, "APrimalBuff.bAOEOnlyApplyOtherBuffToWildDinos" }; }
	BitFieldValue<bool, unsigned __int32> bAoEIgnoreDinosTargetingInstigator() { return { this, "APrimalBuff.bAoEIgnoreDinosTargetingInstigator" }; }
	BitFieldValue<bool, unsigned __int32> bAoEOnlyOnDinosTargetingInstigator() { return { this, "APrimalBuff.bAoEOnlyOnDinosTargetingInstigator" }; }
	BitFieldValue<bool, unsigned __int32> bBuffForceNoTick() { return { this, "APrimalBuff.bBuffForceNoTick" }; }
	BitFieldValue<bool, unsigned __int32> bBuffForceNoTickDedicated() { return { this, "APrimalBuff.bBuffForceNoTickDedicated" }; }
	BitFieldValue<bool, unsigned __int32> bCustomDepthStencilIgnoreHealth() { return { this, "APrimalBuff.bCustomDepthStencilIgnoreHealth" }; }
	BitFieldValue<bool, unsigned __int32> bUseActivateSoundFadeInDuration() { return { this, "APrimalBuff.bUseActivateSoundFadeInDuration" }; }
	BitFieldValue<bool, unsigned __int32> bDinoIgnoreBuffPostprocessEffectWhenRidden() { return { this, "APrimalBuff.bDinoIgnoreBuffPostprocessEffectWhenRidden" }; }
	BitFieldValue<bool, unsigned __int32> bPlayerIgnoreBuffPostprocessEffectWhenRidingDino() { return { this, "APrimalBuff.bPlayerIgnoreBuffPostprocessEffectWhenRidingDino" }; }
	BitFieldValue<bool, unsigned __int32> bRemoteForcedFlee() { return { this, "APrimalBuff.bRemoteForcedFlee" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyActivateSoundForInstigator() { return { this, "APrimalBuff.bOnlyActivateSoundForInstigator" }; }
	BitFieldValue<bool, unsigned __int32> bAOEBuffCarnosOnly() { return { this, "APrimalBuff.bAOEBuffCarnosOnly" }; }
	BitFieldValue<bool, unsigned __int32> bModifyMaxSpeed() { return { this, "APrimalBuff.bModifyMaxSpeed" }; }
	BitFieldValue<bool, unsigned __int32> bDisplayHUDProgressBar() { return { this, "APrimalBuff.bDisplayHUDProgressBar" }; }
	BitFieldValue<bool, unsigned __int32> bForceUsePreventTargeting() { return { this, "APrimalBuff.bForceUsePreventTargeting" }; }
	BitFieldValue<bool, unsigned __int32> bForceUsePreventTargetingTurret() { return { this, "APrimalBuff.bForceUsePreventTargetingTurret" }; }
	BitFieldValue<bool, unsigned __int32> bBPOverrideWeaponBob() { return { this, "APrimalBuff.bBPOverrideWeaponBob" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPModifyPlayerBoneModifiers() { return { this, "APrimalBuff.bUseBPModifyPlayerBoneModifiers" }; }
	BitFieldValue<bool, unsigned __int32> bDediServerUseBPModifyPlayerBoneModifiers() { return { this, "APrimalBuff.bDediServerUseBPModifyPlayerBoneModifiers" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPNonDedicatedPlayerPostAnimUpdate() { return { this, "APrimalBuff.bUseBPNonDedicatedPlayerPostAnimUpdate" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPIsCharacterHardAttached() { return { this, "APrimalBuff.bUseBPIsCharacterHardAttached" }; }
	BitFieldValue<bool, unsigned __int32> bDoCharacterDetachment() { return { this, "APrimalBuff.bDoCharacterDetachment" }; }
	BitFieldValue<bool, unsigned __int32> bDoCharacterDetachmentIncludeRiding() { return { this, "APrimalBuff.bDoCharacterDetachmentIncludeRiding" }; }
	BitFieldValue<bool, unsigned __int32> bDoCharacterDetachmentIncludeCarrying() { return { this, "APrimalBuff.bDoCharacterDetachmentIncludeCarrying" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPInitializedCharacterAnimScriptInstance() { return { this, "APrimalBuff.bUseBPInitializedCharacterAnimScriptInstance" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCanBeCarried() { return { this, "APrimalBuff.bUseBPCanBeCarried" }; }
	BitFieldValue<bool, unsigned __int32> bUsePostAdjustDamage() { return { this, "APrimalBuff.bUsePostAdjustDamage" }; }
	BitFieldValue<bool, unsigned __int32> bAOEApplyOtherBuffOnPlayers() { return { this, "APrimalBuff.bAOEApplyOtherBuffOnPlayers" }; }
	BitFieldValue<bool, unsigned __int32> bAOEApplyOtherBuffOnDinos() { return { this, "APrimalBuff.bAOEApplyOtherBuffOnDinos" }; }
	BitFieldValue<bool, unsigned __int32> bAOEApplyOtherBuffIgnoreSameTeam() { return { this, "APrimalBuff.bAOEApplyOtherBuffIgnoreSameTeam" }; }
	BitFieldValue<bool, unsigned __int32> bAOEApplyOtherBuffRequireSameTeam() { return { this, "APrimalBuff.bAOEApplyOtherBuffRequireSameTeam" }; }
	BitFieldValue<bool, unsigned __int32> bBuffDrawFloatingHUD() { return { this, "APrimalBuff.bBuffDrawFloatingHUD" }; }
	BitFieldValue<bool, unsigned __int32> bAddResetsBuffTime() { return { this, "APrimalBuff.bAddResetsBuffTime" }; }
	BitFieldValue<bool, unsigned __int32> bAoEBuffAllowIfAlreadyBuffed() { return { this, "APrimalBuff.bAoEBuffAllowIfAlreadyBuffed" }; }
	BitFieldValue<bool, unsigned __int32> bNetResetBuffStart() { return { this, "APrimalBuff.bNetResetBuffStart" }; }
	BitFieldValue<bool, unsigned __int32> bImmobilizeTarget() { return { this, "APrimalBuff.bImmobilizeTarget" }; }
	BitFieldValue<bool, unsigned __int32> bForcePlayerProne() { return { this, "APrimalBuff.bForcePlayerProne" }; }
	BitFieldValue<bool, unsigned __int32> bHideBuffFromHUD() { return { this, "APrimalBuff.bHideBuffFromHUD" }; }
	BitFieldValue<bool, unsigned __int32> bHideTimerFromHUD() { return { this, "APrimalBuff.bHideTimerFromHUD" }; }
	BitFieldValue<bool, unsigned __int32> bBPAddMultiUseEntries() { return { this, "APrimalBuff.bBPAddMultiUseEntries" }; }
	BitFieldValue<bool, unsigned __int32> bIsBuffPersistent() { return { this, "APrimalBuff.bIsBuffPersistent" }; }
	BitFieldValue<bool, unsigned __int32> bBPUseBumpedByPawn() { return { this, "APrimalBuff.bBPUseBumpedByPawn" }; }
	BitFieldValue<bool, unsigned __int32> bBPUseBumpedPawn() { return { this, "APrimalBuff.bBPUseBumpedPawn" }; }
	BitFieldValue<bool, unsigned __int32> bAllowBuffWhenInstigatorDead() { return { this, "APrimalBuff.bAllowBuffWhenInstigatorDead" }; }
	BitFieldValue<bool, unsigned __int32> bNotifyDamage() { return { this, "APrimalBuff.bNotifyDamage" }; }
	BitFieldValue<bool, unsigned __int32> bAllowBuffStasis() { return { this, "APrimalBuff.bAllowBuffStasis" }; }
	BitFieldValue<bool, unsigned __int32> bApplyStatModifierToPlayers() { return { this, "APrimalBuff.bApplyStatModifierToPlayers" }; }
	BitFieldValue<bool, unsigned __int32> bApplyStatModifierToDinos() { return { this, "APrimalBuff.bApplyStatModifierToDinos" }; }
	BitFieldValue<bool, unsigned __int32> bPreventOnWildDino() { return { this, "APrimalBuff.bPreventOnWildDino" }; }
	BitFieldValue<bool, unsigned __int32> bPreventOnDino() { return { this, "APrimalBuff.bPreventOnDino" }; }
	BitFieldValue<bool, unsigned __int32> bPreventOnPlayer() { return { this, "APrimalBuff.bPreventOnPlayer" }; }
	BitFieldValue<bool, unsigned __int32> bPreventOnBigDino() { return { this, "APrimalBuff.bPreventOnBigDino" }; }
	BitFieldValue<bool, unsigned __int32> bPreventOnBossDino() { return { this, "APrimalBuff.bPreventOnBossDino" }; }
	BitFieldValue<bool, unsigned __int32> bIsDisease() { return { this, "APrimalBuff.bIsDisease" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPreventAddingOtherBuff() { return { this, "APrimalBuff.bUseBPPreventAddingOtherBuff" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPreventRunning() { return { this, "APrimalBuff.bUseBPPreventRunning" }; }
	BitFieldValue<bool, unsigned __int32> bAoEApplyDamageAllTargetables() { return { this, "APrimalBuff.bAoEApplyDamageAllTargetables" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPActivated() { return { this, "APrimalBuff.bUseBPActivated" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPreventFlight() { return { this, "APrimalBuff.bUseBPPreventFlight" }; }
	BitFieldValue<bool, unsigned __int32> bRequireController() { return { this, "APrimalBuff.bRequireController" }; }
	BitFieldValue<bool, unsigned __int32> bDontPlayInstigatorActiveSoundOnDino() { return { this, "APrimalBuff.bDontPlayInstigatorActiveSoundOnDino" }; }
	BitFieldValue<bool, unsigned __int32> bAddExtendBuffTime() { return { this, "APrimalBuff.bAddExtendBuffTime" }; }
	BitFieldValue<bool, unsigned __int32> bUseTickingDeactivation() { return { this, "APrimalBuff.bUseTickingDeactivation" }; }
	BitFieldValue<bool, unsigned __int32> bCheckPreventInput() { return { this, "APrimalBuff.bCheckPreventInput" }; }
	BitFieldValue<bool, unsigned __int32> bBPDrawBuffStatusHUD() { return { this, "APrimalBuff.bBPDrawBuffStatusHUD" }; }
	BitFieldValue<bool, unsigned __int32> bEnableStaticPathing() { return { this, "APrimalBuff.bEnableStaticPathing" }; }
	BitFieldValue<bool, unsigned __int32> bHUDFormatTimerAsTimecode() { return { this, "APrimalBuff.bHUDFormatTimerAsTimecode" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPreventThrowingItem() { return { this, "APrimalBuff.bUseBPPreventThrowingItem" }; }
	BitFieldValue<bool, unsigned __int32> bPreventInputDoesOffset() { return { this, "APrimalBuff.bPreventInputDoesOffset" }; }
	BitFieldValue<bool, unsigned __int32> bNotifyExperienceGained() { return { this, "APrimalBuff.bNotifyExperienceGained" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyTickWhenVisible() { return { this, "APrimalBuff.bOnlyTickWhenVisible" }; }
	BitFieldValue<bool, unsigned __int32> bBPAdjustStatusValueModification() { return { this, "APrimalBuff.bBPAdjustStatusValueModification" }; }
	BitFieldValue<bool, unsigned __int32> bWasDestroyed() { return { this, "APrimalBuff.bWasDestroyed" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPNotifyOtherBuffActivated() { return { this, "APrimalBuff.bUseBPNotifyOtherBuffActivated" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPNotifyOtherBuffDeactivated() { return { this, "APrimalBuff.bUseBPNotifyOtherBuffDeactivated" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPreventFirstPerson() { return { this, "APrimalBuff.bUseBPPreventFirstPerson" }; }
	BitFieldValue<bool, unsigned __int32> bForceAddUnderwaterCharacterStatusValues() { return { this, "APrimalBuff.bForceAddUnderwaterCharacterStatusValues" }; }

	// Functions

	bool TemplateAllowActorSpawn(UWorld * World, FVector * AtLocation, FRotator * AtRotation, FActorSpawnParameters * SpawnParameters) { return NativeCall<bool, UWorld *, FVector *, FRotator *, FActorSpawnParameters *>(this, "APrimalBuff.TemplateAllowActorSpawn", World, AtLocation, AtRotation, SpawnParameters); }
	void Deactivate() { NativeCall<void>(this, "APrimalBuff.Deactivate"); }
	void NetDeactivate_Implementation() { NativeCall<void>(this, "APrimalBuff.NetDeactivate_Implementation"); }
	void BeginPlay() { NativeCall<void>(this, "APrimalBuff.BeginPlay"); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "APrimalBuff.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void AddDamageStatusValueModifier(APrimalCharacter * addToCharacter, EPrimalCharacterStatusValue::Type ValueType, bool bSpeedToAddInSeconds, bool bContinueOnUnchangedValue, bool bResetExistingModifierDescriptionIndex, bool bSetValue, bool bSetAdditionalValue, float LimitExistingModifierDescriptionToMaxAmount, float damageMultiplierAmountToAdd, float speedToAdd, int StatusValueModifierDescriptionIndex, bool bUsePercentualDamage, bool bMakeUntameable, float percentualDamage, TSubclassOf<UDamageType> ScaleValueByCharacterDamageType) { NativeCall<void, APrimalCharacter *, EPrimalCharacterStatusValue::Type, bool, bool, bool, bool, bool, float, float, float, int, bool, bool, float, TSubclassOf<UDamageType>>(this, "APrimalBuff.AddDamageStatusValueModifier", addToCharacter, ValueType, bSpeedToAddInSeconds, bContinueOnUnchangedValue, bResetExistingModifierDescriptionIndex, bSetValue, bSetAdditionalValue, LimitExistingModifierDescriptionToMaxAmount, damageMultiplierAmountToAdd, speedToAdd, StatusValueModifierDescriptionIndex, bUsePercentualDamage, bMakeUntameable, percentualDamage, ScaleValueByCharacterDamageType); }
	void SetupForInstigator() { NativeCall<void>(this, "APrimalBuff.SetupForInstigator"); }
	void Tick(float DeltaSeconds) { NativeCall<void, float>(this, "APrimalBuff.Tick", DeltaSeconds); }
	void ProcessStaticPathing(bool triggerRunning) { NativeCall<void, bool>(this, "APrimalBuff.ProcessStaticPathing", triggerRunning); }
	FVector * UpdateStaticPathingDestination(FVector * result, FVector locOverride, float randomOffsetMultiplier, bool useRandomNegativeXDir, bool orientRandOffsetByRotation, FRotator randOffsetByRotation, float GroundCheckSpreadOverride) { return NativeCall<FVector *, FVector *, FVector, float, bool, bool, FRotator, float>(this, "APrimalBuff.UpdateStaticPathingDestination", result, locOverride, randomOffsetMultiplier, useRandomNegativeXDir, orientRandOffsetByRotation, randOffsetByRotation, GroundCheckSpreadOverride); }
	void EnableTickFunction() { NativeCall<void>(this, "APrimalBuff.EnableTickFunction"); }
	bool AOEBuffCanAffect(APrimalCharacter * forChar) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalBuff.AOEBuffCanAffect", forChar); }
	void InstigatorJumped() { NativeCall<void>(this, "APrimalBuff.InstigatorJumped"); }
	void Destroyed() { NativeCall<void>(this, "APrimalBuff.Destroyed"); }
	void NetResetBuffStart_Implementation() { NativeCall<void>(this, "APrimalBuff.NetResetBuffStart_Implementation"); }
	bool ResetBuffStart() { return NativeCall<bool>(this, "APrimalBuff.ResetBuffStart"); }
	APrimalBuff * AddBuff(APrimalCharacter * ForCharacter, AActor * DamageCauser) { return NativeCall<APrimalBuff *, APrimalCharacter *, AActor *>(this, "APrimalBuff.AddBuff", ForCharacter, DamageCauser); }
	static APrimalBuff * StaticAddBuff(TSubclassOf<APrimalBuff> BuffClass, APrimalCharacter * ForCharacter, UPrimalItem * AssociatedItem, AActor * DamageCauser, bool bForceOnClient) { return NativeCall<APrimalBuff *, TSubclassOf<APrimalBuff>, APrimalCharacter *, UPrimalItem *, AActor *, bool>(nullptr, "APrimalBuff.StaticAddBuff", BuffClass, ForCharacter, AssociatedItem, DamageCauser, bForceOnClient); }
	bool ExcludePostProcessBlendableMaterial(UMaterialInterface * BlendableMaterialInterface) { return NativeCall<bool, UMaterialInterface *>(this, "APrimalBuff.ExcludePostProcessBlendableMaterial", BlendableMaterialInterface); }
	bool PreventActorTargeting_Implementation(AActor * ByActor) { return NativeCall<bool, AActor *>(this, "APrimalBuff.PreventActorTargeting_Implementation", ByActor); }
	bool PreventRunning() { return NativeCall<bool>(this, "APrimalBuff.PreventRunning"); }
	bool ExcludeAoEActor(AActor * ActorToConsider) { return NativeCall<bool, AActor *>(this, "APrimalBuff.ExcludeAoEActor", ActorToConsider); }
	bool HideBuffFromHUD_Implementation() { return NativeCall<bool>(this, "APrimalBuff.HideBuffFromHUD_Implementation"); }
	void Stasis() { NativeCall<void>(this, "APrimalBuff.Stasis"); }
	void Unstasis() { NativeCall<void>(this, "APrimalBuff.Unstasis"); }
	bool ExtendBuffTime(float AmountOfAdditionalTime) { return NativeCall<bool, float>(this, "APrimalBuff.ExtendBuffTime", AmountOfAdditionalTime); }
	int GetBuffType_Implementation() { return NativeCall<int>(this, "APrimalBuff.GetBuffType_Implementation"); }
	bool ReduceBuffTime(float AmountOfTimeToReduce) { return NativeCall<bool, float>(this, "APrimalBuff.ReduceBuffTime", AmountOfTimeToReduce); }
	static UClass * StaticClass() { return NativeCall<UClass *>(nullptr, "APrimalBuff.StaticClass"); }
	static void StaticRegisterNativesAPrimalBuff() { NativeCall<void>(nullptr, "APrimalBuff.StaticRegisterNativesAPrimalBuff"); }
	void BPDrawBuffStatusHUD(AShooterHUD * HUD, float XPos, float YPos, float ScaleMult) { NativeCall<void, AShooterHUD *, float, float, float>(this, "APrimalBuff.BPDrawBuffStatusHUD", HUD, XPos, YPos, ScaleMult); }
	float BuffAdjustDamage(float Damage, FHitResult * HitInfo, AController * EventInstigator, AActor * DamageCauser, TSubclassOf<UDamageType> TheDamgeType) { return NativeCall<float, float, FHitResult *, AController *, AActor *, TSubclassOf<UDamageType>>(this, "APrimalBuff.BuffAdjustDamage", Damage, HitInfo, EventInstigator, DamageCauser, TheDamgeType); }
	void BuffPostAdjustDamage(float Damage, FHitResult * HitInfo, AController * EventInstigator, AActor * DamageCauser, TSubclassOf<UDamageType> TheDamgeType) { NativeCall<void, float, FHitResult *, AController *, AActor *, TSubclassOf<UDamageType>>(this, "APrimalBuff.BuffPostAdjustDamage", Damage, HitInfo, EventInstigator, DamageCauser, TheDamgeType); }
	void BuffTickClient(float DeltaTime) { NativeCall<void, float>(this, "APrimalBuff.BuffTickClient", DeltaTime); }
	void BuffTickServer(float DeltaTime) { NativeCall<void, float>(this, "APrimalBuff.BuffTickServer", DeltaTime); }
	void DrawBuffFloatingHUD(int BuffIndex, AShooterHUD * HUD, float CenterX, float CenterY, float DrawScale) { NativeCall<void, int, AShooterHUD *, float, float, float>(this, "APrimalBuff.DrawBuffFloatingHUD", BuffIndex, HUD, CenterX, CenterY, DrawScale); }
	void NotifyDamage(float DamageAmount, TSubclassOf<UDamageType> DamageClass, AController * EventInstigator, AActor * TheDamageCauser) { NativeCall<void, float, TSubclassOf<UDamageType>, AController *, AActor *>(this, "APrimalBuff.NotifyDamage", DamageAmount, DamageClass, EventInstigator, TheDamageCauser); }
	bool PreventActorTargeting(AActor * ByActor) { return NativeCall<bool, AActor *>(this, "APrimalBuff.PreventActorTargeting", ByActor); }
	void SetBuffCauser(AActor * CausedBy) { NativeCall<void, AActor *>(this, "APrimalBuff.SetBuffCauser", CausedBy); }
};

struct UPrimalEngramEntry : UObject
{
	int& RequiredCharacterLevelField() { return *GetNativePointerField<int*>(this, "UPrimalEngramEntry.RequiredCharacterLevel"); }
	int& RequiredEngramPointsField() { return *GetNativePointerField<int*>(this, "UPrimalEngramEntry.RequiredEngramPoints"); }
	TSubclassOf<UPrimalItem>& BluePrintEntryField() { return *GetNativePointerField<TSubclassOf<UPrimalItem>*>(this, "UPrimalEngramEntry.BluePrintEntry"); }
	FString& ExtraEngramDescriptionField() { return *GetNativePointerField<FString*>(this, "UPrimalEngramEntry.ExtraEngramDescription"); }
	//TArray<FEngramEntries>& EngramRequirementSetsField() { return *GetNativePointerField<TArray<FEngramEntries>*>(this, "UPrimalEngramEntry.EngramRequirementSets"); }
	int& MyEngramIndexField() { return *GetNativePointerField<int*>(this, "UPrimalEngramEntry.MyEngramIndex"); }
	TEnumAsByte<enum EEngramGroup::Type>& EngramGroupField() { return *GetNativePointerField<TEnumAsByte<enum EEngramGroup::Type>*>(this, "UPrimalEngramEntry.EngramGroup"); }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bGiveBlueprintToPlayerInventory() { return { this, "UPrimalEngramEntry.bGiveBlueprintToPlayerInventory" }; }
	BitFieldValue<bool, unsigned __int32> bCanBeManuallyUnlocked() { return { this, "UPrimalEngramEntry.bCanBeManuallyUnlocked" }; }

	// Functions

	UObject * GetObjectW() { return NativeCall<UObject *>(this, "UPrimalEngramEntry.GetObjectW"); }
	FString * GetEntryString(FString * result) { return NativeCall<FString *, FString *>(this, "UPrimalEngramEntry.GetEntryString", result); }
	UTexture2D * GetEntryIcon(UObject * AssociatedDataObject, bool bIsEnabled) { return NativeCall<UTexture2D *, UObject *, bool>(this, "UPrimalEngramEntry.GetEntryIcon", AssociatedDataObject, bIsEnabled); }
	bool MeetsEngramRequirements(AShooterPlayerState * aPlayerState, bool bOnlyCheckLevel, bool bDontCheckEngramPreRequirements) { return NativeCall<bool, AShooterPlayerState *, bool, bool>(this, "UPrimalEngramEntry.MeetsEngramRequirements", aPlayerState, bOnlyCheckLevel, bDontCheckEngramPreRequirements); }
	bool MeetsEngramChainRequirements(AShooterPlayerState * aPlayerState) { return NativeCall<bool, AShooterPlayerState *>(this, "UPrimalEngramEntry.MeetsEngramChainRequirements", aPlayerState); }
	FString * GetEngramDescription(FString * result, AShooterPlayerState * aPlayerState) { return NativeCall<FString *, FString *, AShooterPlayerState *>(this, "UPrimalEngramEntry.GetEngramDescription", result, aPlayerState); }
	FString * GetEngramName(FString * result) { return NativeCall<FString *, FString *>(this, "UPrimalEngramEntry.GetEngramName", result); }
	int GetRequiredEngramPoints() { return NativeCall<int>(this, "UPrimalEngramEntry.GetRequiredEngramPoints"); }
	int GetRequiredLevel() { return NativeCall<int>(this, "UPrimalEngramEntry.GetRequiredLevel"); }
	bool UseEngramRequirementSets() { return NativeCall<bool>(this, "UPrimalEngramEntry.UseEngramRequirementSets"); }
	bool IsEngramClassHidden(TSubclassOf<UPrimalItem> ForItemClass) { return NativeCall<bool, TSubclassOf<UPrimalItem>>(this, "UPrimalEngramEntry.IsEngramClassHidden", ForItemClass); }
	void GetAllChainedPreReqs(AShooterPlayerState * aPlayerState, TArray<TSubclassOf<UPrimalEngramEntry>> * TestedEntries) { NativeCall<void, AShooterPlayerState *, TArray<TSubclassOf<UPrimalEngramEntry>> *>(this, "UPrimalEngramEntry.GetAllChainedPreReqs", aPlayerState, TestedEntries); }
	int GetChainRequiredEngramPoints(TArray<TSubclassOf<UPrimalEngramEntry>> * TestedEntries) { return NativeCall<int, TArray<TSubclassOf<UPrimalEngramEntry>> *>(this, "UPrimalEngramEntry.GetChainRequiredEngramPoints", TestedEntries); }
	void ClearHiddenEngramRequirements() { NativeCall<void>(this, "UPrimalEngramEntry.ClearHiddenEngramRequirements"); }
};

struct FDinoAncestorsEntry
{
	FString MaleName;
	unsigned int MaleDinoID1;
	unsigned int MaleDinoID2;
	FString FemaleName;
	unsigned int FemaleDinoID1;
	unsigned int FemaleDinoID2;
};

struct FCraftingResourceRequirement
{
	float BaseResourceRequirement;
	TSubclassOf<UPrimalItem> ResourceItemType;
	bool bCraftingRequireExactResourceType;
};

struct UKismetSystemLibrary
{
	static FString * GetDisplayName(FString * result, UObject * Object) { return NativeCall<FString *, FString *, UObject *>(nullptr, "UKismetSystemLibrary.GetDisplayName", result, Object); }
	static bool IsDedicatedServer(UObject * WorldContextObject) { return NativeCall<bool, UObject *>(nullptr, "UKismetSystemLibrary.IsDedicatedServer", WorldContextObject); }
	static void K2_SetTimer(UObject * Object, FString FunctionName, float Time, bool bLooping) { NativeCall<void, UObject *, FString, float, bool>(nullptr, "UKismetSystemLibrary.K2_SetTimer", Object, FunctionName, Time, bLooping); }
	static void K2_SetTimerForNextTick(UObject * Object, FString FunctionName, bool bLooping) { NativeCall<void, UObject *, FString, bool>(nullptr, "UKismetSystemLibrary.K2_SetTimerForNextTick", Object, FunctionName, bLooping); }
	static void K2_ClearTimer(UObject * Object, FString FunctionName) { NativeCall<void, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_ClearTimer", Object, FunctionName); }
	static void K2_PauseTimer(UObject * Object, FString FunctionName) { NativeCall<void, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_PauseTimer", Object, FunctionName); }
	static void K2_UnPauseTimer(UObject * Object, FString FunctionName) { NativeCall<void, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_UnPauseTimer", Object, FunctionName); }
	static bool K2_IsTimerActive(UObject * Object, FString FunctionName) { return NativeCall<bool, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_IsTimerActive", Object, FunctionName); }
	static bool K2_IsTimerPaused(UObject * Object, FString FunctionName) { return NativeCall<bool, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_IsTimerPaused", Object, FunctionName); }
	static bool K2_TimerExists(UObject * Object, FString FunctionName) { return NativeCall<bool, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_TimerExists", Object, FunctionName); }
	static float K2_GetTimerElapsedTime(UObject * Object, FString FunctionName) { return NativeCall<float, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_GetTimerElapsedTime", Object, FunctionName); }
	static float K2_GetTimerRemainingTime(UObject * Object, FString FunctionName) { return NativeCall<float, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_GetTimerRemainingTime", Object, FunctionName); }
	static void SetClassPropertyByName(UObject * Object, FName PropertyName, TSubclassOf<UObject> Value) { NativeCall<void, UObject *, FName, TSubclassOf<UObject>>(nullptr, "UKismetSystemLibrary.SetClassPropertyByName", Object, PropertyName, Value); }
	static void SetVectorPropertyByName(UObject * Object, FName PropertyName, FVector * Value) { NativeCall<void, UObject *, FName, FVector *>(nullptr, "UKismetSystemLibrary.SetVectorPropertyByName", Object, PropertyName, Value); }
	static void SetRotatorPropertyByName(UObject * Object, FName PropertyName, FRotator * Value) { NativeCall<void, UObject *, FName, FRotator *>(nullptr, "UKismetSystemLibrary.SetRotatorPropertyByName", Object, PropertyName, Value); }
	static void SetLinearColorPropertyByName(UObject * Object, FName PropertyName, FLinearColor * Value) { NativeCall<void, UObject *, FName, FLinearColor *>(nullptr, "UKismetSystemLibrary.SetLinearColorPropertyByName", Object, PropertyName, Value); }
	static void SetTransformPropertyByName(UObject * Object, FName PropertyName, FTransform * Value) { NativeCall<void, UObject *, FName, FTransform *>(nullptr, "UKismetSystemLibrary.SetTransformPropertyByName", Object, PropertyName, Value); }
	static void GetActorListFromComponentList(TArray<UPrimitiveComponent *> * ComponentList, UClass * ActorClassFilter, TArray<AActor *> * OutActorList) { NativeCall<void, TArray<UPrimitiveComponent *> *, UClass *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.GetActorListFromComponentList", ComponentList, ActorClassFilter, OutActorList); }
	static bool SphereOverlapActors_NEW(UObject * WorldContextObject, FVector SpherePos, float SphereRadius, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ActorClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<AActor *> * OutActors) { return NativeCall<bool, UObject *, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.SphereOverlapActors_NEW", WorldContextObject, SpherePos, SphereRadius, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool SphereOverlapActorsSimple(UObject * WorldContextObject, FVector SpherePos, float SphereRadius, TEnumAsByte<enum EObjectTypeQuery> ObjectType, UClass * ActorClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<AActor *> * OutActors) { return NativeCall<bool, UObject *, FVector, float, TEnumAsByte<enum EObjectTypeQuery>, UClass *, TArray<AActor *> *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.SphereOverlapActorsSimple", WorldContextObject, SpherePos, SphereRadius, ObjectType, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool SphereOverlapComponents_NEW(UObject * WorldContextObject, FVector SpherePos, float SphereRadius, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ComponentClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<UPrimitiveComponent *> * OutComponents) { return NativeCall<bool, UObject *, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<UPrimitiveComponent *> *>(nullptr, "UKismetSystemLibrary.SphereOverlapComponents_NEW", WorldContextObject, SpherePos, SphereRadius, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	static bool BoxOverlapActors_NEW(UObject * WorldContextObject, FVector BoxPos, FVector BoxExtent, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ActorClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<AActor *> * OutActors) { return NativeCall<bool, UObject *, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.BoxOverlapActors_NEW", WorldContextObject, BoxPos, BoxExtent, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool BoxOverlapComponents_NEW(UObject * WorldContextObject, FVector BoxPos, FVector BoxExtent, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ComponentClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<UPrimitiveComponent *> * OutComponents) { return NativeCall<bool, UObject *, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<UPrimitiveComponent *> *>(nullptr, "UKismetSystemLibrary.BoxOverlapComponents_NEW", WorldContextObject, BoxPos, BoxExtent, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	static bool CapsuleOverlapActors_NEW(UObject * WorldContextObject, FVector CapsulePos, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ActorClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<AActor *> * OutActors) { return NativeCall<bool, UObject *, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.CapsuleOverlapActors_NEW", WorldContextObject, CapsulePos, Radius, HalfHeight, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool CapsuleOverlapComponents_NEW(UObject * WorldContextObject, FVector CapsulePos, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ComponentClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<UPrimitiveComponent *> * OutComponents) { return NativeCall<bool, UObject *, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<UPrimitiveComponent *> *>(nullptr, "UKismetSystemLibrary.CapsuleOverlapComponents_NEW", WorldContextObject, CapsulePos, Radius, HalfHeight, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	static bool ComponentOverlapActors_NEW(UPrimitiveComponent * Component, FTransform * ComponentTransform, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ActorClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<AActor *> * OutActors) { return NativeCall<bool, UPrimitiveComponent *, FTransform *, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.ComponentOverlapActors_NEW", Component, ComponentTransform, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool ComponentOverlapComponents_NEW(UPrimitiveComponent * Component, FTransform * ComponentTransform, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ComponentClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<UPrimitiveComponent *> * OutComponents) { return NativeCall<bool, UPrimitiveComponent *, FTransform *, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<UPrimitiveComponent *> *>(nullptr, "UKismetSystemLibrary.ComponentOverlapComponents_NEW", Component, ComponentTransform, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	static bool BoxTraceSingle(UObject * WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, ETraceTypeQuery TraceChannel, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult * OutHit, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, FVector, FRotator, ETraceTypeQuery, bool, TArray<AActor *> *, EDrawDebugTrace::Type, FHitResult *, bool>(nullptr, "UKismetSystemLibrary.BoxTraceSingle", WorldContextObject, Start, End, HalfSize, Orientation, TraceChannel, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool BoxTraceMulti(UObject * WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, ETraceTypeQuery TraceChannel, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult> * OutHits, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, FVector, FRotator, ETraceTypeQuery, bool, TArray<AActor *> *, EDrawDebugTrace::Type, TArray<FHitResult> *, bool>(nullptr, "UKismetSystemLibrary.BoxTraceMulti", WorldContextObject, Start, End, HalfSize, Orientation, TraceChannel, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool LineTraceSingleForObjects(UObject * WorldContextObject, FVector Start, FVector End, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult * OutHit, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, FHitResult *, bool>(nullptr, "UKismetSystemLibrary.LineTraceSingleForObjects", WorldContextObject, Start, End, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool LineTraceMultiForObjects(UObject * WorldContextObject, FVector Start, FVector End, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult> * OutHits, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, TArray<FHitResult> *, bool>(nullptr, "UKismetSystemLibrary.LineTraceMultiForObjects", WorldContextObject, Start, End, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool SphereTraceSingleForObjects(UObject * WorldContextObject, FVector Start, FVector End, float Radius, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult * OutHit, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, FHitResult *, bool>(nullptr, "UKismetSystemLibrary.SphereTraceSingleForObjects", WorldContextObject, Start, End, Radius, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool SphereTraceMultiForObjects(UObject * WorldContextObject, FVector Start, FVector End, float Radius, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult> * OutHits, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, TArray<FHitResult> *, bool>(nullptr, "UKismetSystemLibrary.SphereTraceMultiForObjects", WorldContextObject, Start, End, Radius, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool BoxTraceSingleForObjects(UObject * WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult * OutHit, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, FVector, FRotator, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, FHitResult *, bool>(nullptr, "UKismetSystemLibrary.BoxTraceSingleForObjects", WorldContextObject, Start, End, HalfSize, Orientation, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool BoxTraceMultiForObjects(UObject * WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult> * OutHits, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, FVector, FRotator, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, TArray<FHitResult> *, bool>(nullptr, "UKismetSystemLibrary.BoxTraceMultiForObjects", WorldContextObject, Start, End, HalfSize, Orientation, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool CapsuleTraceSingleForObjects(UObject * WorldContextObject, FVector Start, FVector End, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult * OutHit, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, FHitResult *, bool>(nullptr, "UKismetSystemLibrary.CapsuleTraceSingleForObjects", WorldContextObject, Start, End, Radius, HalfHeight, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool CapsuleTraceMultiForObjects(UObject * WorldContextObject, FVector Start, FVector End, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult> * OutHits, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, TArray<FHitResult> *, bool>(nullptr, "UKismetSystemLibrary.CapsuleTraceMultiForObjects", WorldContextObject, Start, End, Radius, HalfHeight, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static void DrawDebugFrustum(UObject * WorldContextObject, FTransform * FrustumTransform, FLinearColor FrustumColor, float Duration) { NativeCall<void, UObject *, FTransform *, FLinearColor, float>(nullptr, "UKismetSystemLibrary.DrawDebugFrustum", WorldContextObject, FrustumTransform, FrustumColor, Duration); }
	static void GetActorBounds(AActor * Actor, FVector * Origin, FVector * BoxExtent) { NativeCall<void, AActor *, FVector *, FVector *>(nullptr, "UKismetSystemLibrary.GetActorBounds", Actor, Origin, BoxExtent); }
	static int GetRenderingDetailMode() { return NativeCall<int>(nullptr, "UKismetSystemLibrary.GetRenderingDetailMode"); }
	static int GetRenderingMaterialQualityLevel() { return NativeCall<int>(nullptr, "UKismetSystemLibrary.GetRenderingMaterialQualityLevel"); }
	static void ShowPlatformSpecificAchievementsScreen(APlayerController * SpecificPlayer) { NativeCall<void, APlayerController *>(nullptr, "UKismetSystemLibrary.ShowPlatformSpecificAchievementsScreen", SpecificPlayer); }
};
