#
# MTK-factory read and write
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mtkhqos_util
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)
PKG_CONFIG_DEPENDS:=

include $(INCLUDE_DIR)/package.mk

define Package/mtkhqos_util
  SECTION:=net
  CATEGORY:=Network
  TITLE:=mtk hqos utility
  VERSION:=$(PKG_RELEASE)-$(REVISION)
endef

define Package/mtkhqos_util/description
  mtk hqos util
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Compile/Default
endef

Build/Compile = $(Build/Compile/Default)

define Package/mtkhqos_util/install
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_DIR) $(1)/etc/init.d
	
	$(INSTALL_DIR) $(1)/lib/wifi/
	$(INSTALL_DIR) $(1)/etc/wireless/mt7615/
	$(INSTALL_DIR) $(1)/etc_ro/Wireless/RT2860AP/
	$(INSTALL_BIN) ./files/l1profile.dat $(1)/etc/wireless/
	$(INSTALL_BIN) ./files/mt7615.1.2G.dat $(1)/etc/wireless/mt7615/
	$(INSTALL_BIN) ./files/mt7615.1.5G.dat $(1)/etc/wireless/mt7615/
	$(INSTALL_BIN) ./files/mt7615.lua $(1)/lib/wifi
	$(INSTALL_BIN) ./files/firmware.sh $(1)/etc/init.d/
	$(INSTALL_BIN) ./files/apcli.sh $(1)/etc/init.d/

	$(INSTALL_BIN) ./files/mtkhqos $(1)/sbin/
	$(INSTALL_BIN) ./files/mtkhqos.config $(1)/etc/config/mtkhqos
	$(INSTALL_BIN) ./files/mtkhqos.init $(1)/etc/init.d/mtkhqos
endef

$(eval $(call BuildPackage,mtkhqos_util))
