#
#
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=dht11
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define KernelPackage/dht11
  SUBMENU:=Other modules
  TITLE:=dht11
  FILES:=$(PKG_BUILD_DIR)/dht11.ko
  KCONFIG:=
endef

define KernelPackage/dht11/description
  This is a dht11 drivers
endef

MAKE_OPTS:= \
	ARCH="$(LINUX_KARCH)" \
	CROSS_COMPILE="$(TARGET_CROSS)" \
	SUBDIRS="$(PKG_BUILD_DIR)"

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) -C "$(LINUX_DIR)" \
	$(MAKE_OPTS) modules
endef

$(eval $(call KernelPackage,dht11))
