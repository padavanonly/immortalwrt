include $(TOPDIR)/rules.mk

PKG_NAME:=luci-app-mtwifi
PKG_LICENSE:=GPLv2
PKG_MAINTAINER:=Hua Shao <nossiac@163.com>

LUCI_TITLE:=LuCI support for mt wifi driver
LUCI_PKGARCH:=all
PKG_VERSION:=1
PKG_RELEASE:=8

define Package/luci-app-mtwifi
endef




include $(TOPDIR)/feeds/luci/luci.mk
$(eval $(call BuildPackage,luci-app-mtwifi))
# call BuildPackage OpenWrt buildroot signature
