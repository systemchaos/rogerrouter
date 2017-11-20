PKG             := glib-networking
$(PKG)_WEBSITE  := https://www.gnome.org
$(PKG)_DESCR    := Network-related GIO modules for glib
$(PKG)_IGNORE   :=
$(PKG)_VERSION  := 2.54.1
$(PKG)_CHECKSUM := eaa787b653015a0de31c928e9a17eb57b4ce23c8cf6f277afaec0d685335012f
$(PKG)_SUBDIR   := glib-networking-$($(PKG)_VERSION)
$(PKG)_FILE     := glib-networking-$($(PKG)_VERSION).tar.xz
$(PKG)_URL      := https://download.gnome.org/sources/$(PKG)/2.54/$($(PKG)_FILE)
$(PKG)_DEPS     := gcc gnutls

define $(PKG)_UPDATE
#    $(WGET) -q -O- 'https://git.xiph.org/?p=speex.git;a=tags' | \
#    grep '<a class="list name"' | \
#    $(SED) -n 's,.*<a[^>]*>Speex-\([0-9][^<]*\)<.*,\1,p' | \
#    head -1
endef

define $(PKG)_BUILD
    cd '$(1)' && ./configure \
	$(subst docdir$(comma),,$(MXE_CONFIGURE_OPTS))
    $(MAKE) -C '$(1)'
    $(MAKE) -C '$(1)' install
endef
