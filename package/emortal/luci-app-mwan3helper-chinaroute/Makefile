# Copyright (C) 2016 Openwrt.org
#
# This is free software, licensed under the Apache License, Version 2.0 .
#

include $(TOPDIR)/rules.mk

LUCI_TITLE:=LuCI support for MWAN3 Helper chinaroute
LUCI_DEPENDS:= dnsmasq-full +ipset @!PACKAGE_luci-app-eqos
LUCI_PKGARCH:=all
PKG_VERSION:=1
PKG_RELEASE:=3

include $(TOPDIR)/feeds/luci/luci.mk


# call BuildPackage - OpenWrt buildroot signature


