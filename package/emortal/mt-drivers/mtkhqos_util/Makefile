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
  mtk hqos util to init hnat module
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
	$(INSTALL_DIR) $(1)/etc/uci-defaults

	$(INSTALL_BIN) ./files/mtkhnat $(1)/sbin/
	$(INSTALL_BIN) ./files/mtkhnat.config $(1)/etc/config/mtkhnat
	$(INSTALL_BIN) ./files/mtkhnat.init $(1)/etc/init.d/mtkhnat
	$(INSTALL_BIN) ./files/99-firewall $(1)/etc/uci-defaults	
endef

$(eval $(call BuildPackage,mtkhqos_util))
