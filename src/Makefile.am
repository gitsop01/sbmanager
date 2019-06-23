 AM_CFLAGS =			\
	$(GLOBAL_CFLAGS)	\
	$(libimobiledevice_CFLAGS)	\
	$(libglib2_CFLAGS)	\
	$(libgthread2_CFLAGS)	\
	$(libplist_CFLAGS)	\
	$(libclutter_CFLAGS)	\
	$(libcluttergtk_CFLAGS)	\
	$(libgtk3_CFLAGS)	\
	$(libgdkpixbuf_CFLAGS)	\
	-DSBMGR_DATA=\"$(pkgdatadir)\"

 AM_LDFLAGS =			\
	$(libimobiledevice_LIBS)	\
	$(libglib2_LIBS)	\
	$(libgthread2_LIBS)	\
	$(libplist_LIBS)	\
	$(libclutter_LIBS)	\
	$(libcluttergtk_LIBS)	\
	$(libgtk3_LIBS)		\
	$(libgdkpixbuf_LIBS)

 bin_PROGRAMS = sbmanager

 noinst_LTLIBRARIES = libsbmanager.la
 libsbmanager_la_SOURCES = sb.device.c sb.device.h \
			sb.utility.c sb.utility.h \
			sb.gui.c sb.gui.h \
			sb.item.c sb.item.h \
			sb.mgr.c sb.mgr.h \
          	        sb.app.c sb.app.h
 libsbmanager_la_CFLAGS = $(AM_CFLAGS)
 libsbmanager_la_LIBADD = $(AM_LDFLAGS)

 sbmanager_SOURCES = main.c
 sbmanager_CFLAGS = $(AM_CFLAGS)
 sbmanager_LDFLAGS = $(AM_LDFLAGS)
 sbmanager_LDADD = libsbmanager.la


