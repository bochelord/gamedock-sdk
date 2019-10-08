//
//  HookBridge.h
//  Gamedock
//
//  Copyright (c) 2015 Azerion. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface HookBridge : NSObject

// --- Native ObjC ---

+ (void)sendMessageToUnity:(NSString*)messageName withParameter:(NSString*)parameterString;
+ (NSString*)getLocalSecret;

// --- C Hookbridge ---

#ifdef __cplusplus
extern "C" {
    // --- External ---
    
    // NOTE: Not defined in GamedockiOSUnityImplementation.cs & HookBridge.mm, implemented by unity
    void UnitySendMessage(const char* obj, const char* method, const char* msg);
    
    // NOTE: Not defined in GamedockiOSUnityImplementation.cs & HookBridge.mm, implemented in libGamedockSDKiOSAuth.a
    char* getLocalSecretEx();
    
    // --- GDPR ---
    
    void checkPrivacyPolicyNative(bool coppaEnabled, const char* externalIds);
    
    void showPrivacyPolicySettings();
    
    void checkAgeGateNative(bool shouldBlock, int requiredAge);
    
    void savePrivValueNative(int priv);
    
    int getPrivValueNative();
    
    // --- Util ---
    
    void setCustomBundleIdNative(const char* bundleId);
    
    char* getGamedockUserIdNative();
    
    void setPluginInformationNative(const char* pluginName, const char* pluginVersion);
    
    void recordFPSValueNative(double fpsValue);
    
    void addExternalIdNative(const char* externalPartner, const char* externalPartnerId);
    
    void removeExternalPartnerNative(const char* externalPartner);
    
    void requestServerTimeNative();
    
    void showDialogNative(char* title, char* message, char* okButtonText);
    
    // --- Event tracking ---
    
    void initEventTrackerWithOptions(const char* options, const char* externalIds);
    
    void trackEventNative(const char* eventName);
    
    void trackEventWithParamsNative(const char* eventName, const char* jsonStringParams);
    
    // --- Default events (Not used by the unity plugin, it uses the generic track event methods) ---
    
    void trackMilestoneAchievedEvent(const char* name);
    
    void trackLevelStartEvent(const char* level, bool customCreated, const char* creatorId);
    
    void trackLevelCompleteEvent(const char* level, int score, int stars, int turns, bool customCreated, const char* creatorId);
    
    void trackLevelFailed(const char* level, int score, int stars, int turns, bool customCreated, const char* creatorId);

    void trackLevelUpEvent(const char* level, const char* objectId, const char* skillId);

    void trackEquipEvent(const char* equippedItem, const char* equippedTo);
    
    void trackUpgradeEvent(const char* upgradeId, const char* level, const char* reason, int iteration);
    
    void trackLevelCreateEvent(const char* levelId, const char* creatorId);
    
    void trackLevelDownloadEvent(const char* levelId, const char* creatorId, int rating);
    
    void trackLevelRateEvent(const char* levelId, const char* creatorId, int rating);

    void trackEndlessModeStartEvent();
    
    void trackEndlessModeEndEvent(int distance);

    void trackPlayerDiesEvent(const char* level);
    
    void trackWalletInventoryEvent(const char* currencyList, const char* itemsList, const char* reason, const char* location);
    
    void trackIAPPurchasedEvent(const char* skuId, const char* transactionId, const char* purchaseDate, const char* reasonDetailsData);

    void trackIAPRestoredEvent(const char* skuId, const char* originalTransactionId, const char* originalPurchaseDate);

    void trackIAPFailedEvent(const char* skuId, const char* error);

    void trackTutorialCompleteEvent();
    
    void trackTutorialSkippedEvent();
    
    void trackRegisterEvent(const char* platform);

    void trackShareEvent(const char* platform);

    void trackInviteEvent(const char* platform);
    
    // --- Push messages ---
    
    void disableAutomaticRegisterForPushNotificationsNative();
    
    void registerForPushNotifications();
    
    // --- Token claiming ---
    
    void claimTokenNative(const char* token, const char* rewardType);
    
    // --- Config ---
    
    void requestGameConfigNative();
    
    char* getConfigNative();
    
    char* getConfigValueNative(const char* keyName);
    
    // --- Packages & Promotions ---
    
    char* getAllPackagesNative();
    
    char* getAllPromotionsNative();
    
    char* getPackageNative(const char* packageId); // NOTE: Changed param name
    
    char* getPackageByIDNative(int packageId); // NOTE: New method
    
    char* getBundlePromotionNative(int bundleId); // NOTE: Method name change
    
    char* getPackagePromotionNative(const char* packageId); // NOTE: New method
    
    void requestPackagesNative();
    
    void requestPromotionsNative();
    
    char* getContainersConfigurationNative();
    
    char* getMissionsConfigurationNative(const char* containerId);
    
    void showPromotionScreenNative(int promotionId);
    
    // --- ADS ---
    
    void requestMoreAppsNative();
    
    void showMoreAppsNative();
    
    void requestRewardVideoNative(const char* location, const char* rewardType);

    void playRewardVideoNative(const char* location, const char* rewardType);
    
    void showToastOnVideoReward(const bool enabled);
    
    void closedParentalGateNative(const bool pass);
    
    void requestBannerAdNative(const char* position, const char* format);
    
    void showInterstitialAdNative(const char* adProvider);
    
    void showBannerAdNative();
    
    void hideBannerAdNative();
    
    void devRequestAdNative(const char* providerName, const char* adTypeName, const bool parentalGate);
    
    // --- Game & Player data ---
    
    void updatePlayerDataNative();

    char* getWalletNative();
    
    char* getGamedockGameDataNative();
    
    char* getInventoryNative();
    
    void addCurrencyToWalletNative(int currencyId, int amount, char* reasonName, char* location, char* reasonDetails, char* transactionId);
    
    void subtractCurrencyFromWalletNative(int currencyId, int amount, char* reasonName, char* location, char* reasonDetails, char* transactionId);
    
    void addItemToInventoryNative(int itemId, int amount, char* reasonName, char* location, char* reasonDetails, char* transactionId);
    
    void subtractItemFromInventoryNative(int itemId, int amount, char* reasonName, char* location, char* reasonDetails, char* transactionId);
    
    void buyBundleNative(int itemId, char* reasonName, char* location, char* reasonDetails, char* transactionId, char* perkItemJson);
    
    void openGachaNative(int itemId, char* reasonName, char* reasonDetails, char* location, char* perkItemJson);
    
    void resetPlayerDataNative();
    
    void resetMissionDataNative();
    
    void resetInventoryNative();
    
    void resetWalletNative();
    
    void setCurrencyLimitNative(int currencyId, int limit);
    
    void setItemLimitNative(int itemId, int limit);
    
    char* getUserAllContainerProgressNative();
    
    char* getUserAllMissionProgressNative();
    
    void updateContainerProgressNative(char* containerProgressList, char* reason, char* reasonDetails, char* location, char* transactionId);
    
    void updateContainerAndMissionProgressNative(char* containerProgressList, char* missionProgressList, char* reason, char* reasonDetails, char* location, char* transactionId);
    
    void updateMissionProgressNative(char* missionProgressList, char* reason, char* reasonDetails, char* location, char* transactionId);
    
    void claimContainersRewardNative(char* containerProgressList, char* reason, char* reasonDetails, char* location, char* transactionId);
    
    void claimMissionsRewardNative(char* missionProgressList, char* reason, char* reasonDetails, char* location, char* transactionId);
    
    char* createUniqueItemNative(int itemId, char* uniqueId);
    
    void addUniqueItemToInventoryNative(char* uniquePlayerItemJSON, char* reason, char* reasonDetails, char* location, char* transactionId);
    
    void updateUniqueItemFromInventoryNative(char* uniquePlayerItemJSON, char* reason, char* reasonDetails, char* location, char* transactionId);
    
    void removeUniqueItemFromInventoryNative(char* uniquePlayerItemJSON, char* reason, char* reasonDetails, char* location, char* transactionId);
    
    // --- Customer support ---
    
    void showHelpCenterWebviewNative(char* url, char* tags);
    
    // --- Daily bonus ---
    
    void requestDailyBonusNative();
    
    void showDailyBonusNative();
    
    char* getDailyBonusConfigNative();
    
    void collectDailyBonusNative();
    
    // --- Splashscreens ---
    
    void requestSplashScreenNative(const char* type);
    
    void showSplashScreenNative();
    
    // --- User data ---
    
    char* getExternalUserIdNative();
    
    char* getExternalUserProviderNative();
    
    void setExternalUserIdNative(const char* providerId, const char* userId);

    void setPrivateGameStateNative(const char* privateData);

    char* getPrivateGameStateNative();

    void setPublicGameStateNative(const char* publicData);
    
    char* getPublicGameStateNative();

    void getOtherUsersGameStateNative(const char* provider, const char* userIdsJsonArray);
    
    // --- Image cache ---
    
    char* getImagePathNative(char* url);
        
    void requestImageNative(char* url, int idx, char* imageType);
    
    void clearDiskCacheNative();
    
    void preloadItemAndBundleImagesNative();
    
    // --- Live events ---
    
    void requestLiveEventNative();
    
    void openLiveEventNative();
    
    char* getLiveEventStartDateNative();
    
    char* getLiveEventEndDateNative();
    
    char* getLiveEventConfigNative();
    
    // --- Tiered events ---
    
    void requestTieredEventsNative();
    
    char* getAllTieredEventsNative();
    
    char* getTieredEventProgressNative(int tieredEventId);
    
    void showTieredEventProgressNative(int tieredEventId);
    
    // --- Login ---
    
    void loginNative(char* externalUserId, char* externalProviderId, char* externalToken, char* socialValidationData);
    
    bool isLoggedInNative();
    
    void logoutNative(bool global);
    
    void userPlayAsGuestNative();
    
    void showAuthorizedDialogNative(char* title, char* message, char* loginButtonText, char* guestButtonText);
    
    void resetDataNative();
    
    void confirmUserIdChangeNative();
    
    // --- Data syncing ---
    
    char* getDeviceIdNative();
    
    void requestUserDataNative();
    
    void mergeUserDataNative(char* mergedUserData, char* mergeType);
    
    void showMergeConflictDialogNative(char* title, char* message, char* localButtonText, char* remoteButtonText, char* mergeButtonText);
    
    void showSyncErrorDialogNative(char* title, char* message, char* mergeButtonText);
    
    void showMergeFailedDialogNative(char* title, char* message, char* retryButtonText, char* mergeData, char* mergeType);
    
    // --- Asset bundles ---
    
    void requestAssetBundlesNative();
    
    char* getAssetBundlesNative();
    
    // --- Firebase ---
    
    void requestFirebaseRemoteConfigNative(long cacheExpirationTime);
    
    void setFirebaseRemoteConfigDefaultsNative(char* defaultValues);
    
    bool getBooleanFirebaseRemoteConfigNative(char* key, char* namespaceValue);
    
    double getDoubleFirebaseRemoteConfigNative(char* key, char* namespaceValue);
    
    long getLongFirebaseRemoteConfigNative(char* key, char* namespaceValue);
    
    char* getStringFirebaseRemoteConfigNative(char* key, char* namespaceValue);
}

#endif

@end