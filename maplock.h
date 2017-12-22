#ifndef _MAPLOCK_H
#define _MAPLOCK_H

struct map_struct
{
   const char *path;
   void  *addr;
   size_t length;
};

struct map_struct native_tbl[] = {
    //arm64
    { "/system/bin/app_process64", NULL, 0 },
    { "/system/bin/linker64", NULL, 0 },

    { "/system/lib64/libandroid.so", NULL, 0 },
    { "/system/lib64/libandroid_runtime.so", NULL, 0 },
    { "/system/lib64/libart.so", NULL, 0 },
    { "/system/lib64/libbinder.so", NULL, 0 },
    { "/system/lib64/libc++.so", NULL, 0 },
    { "/system/lib64/libc.so", NULL, 0 },
    { "/system/lib64/libcrypto.so", NULL, 0 },
    { "/system/lib64/libcutils.so", NULL, 0 },
    { "/system/lib64/libicui18n.so", NULL, 0 },
    { "/system/lib64/libjpeg.so", NULL, 0 },
    { "/system/lib64/libm.so", NULL, 0 },
    { "/system/lib64/libpcre.so", NULL, 0 },
    { "/system/lib64/libpng.so", NULL, 0 },
    { "/system/lib64/libselinux.so", NULL, 0 },
    { "/system/lib64/libsqlite.so", NULL, 0 },
    { "/system/lib64/libssl.so", NULL, 0 },
    { "/system/lib64/libstdc++.so", NULL, 0 },
    { "/system/lib64/libz.so", NULL, 0 },

    //arm32
    { "/system/bin/app_process32", NULL, 0 },
    { "/system/bin/linker", NULL, 0 },

    { "/system/lib/libandroid.so", NULL, 0 },
    { "/system/lib/libandroid_runtime.so", NULL, 0 },
    { "/system/lib/libart.so", NULL, 0 },
    { "/system/lib/libbinder.so", NULL, 0 },
    { "/system/lib/libc++.so", NULL, 0 },
    { "/system/lib/libc.so", NULL, 0 },
    { "/system/lib/libcrypto.so", NULL, 0 },
    { "/system/lib/libcutils.so", NULL, 0 },
    { "/system/lib/libicui18n.so", NULL, 0 },
    { "/system/lib/libjpeg.so", NULL, 0 },
    { "/system/lib/libm.so", NULL, 0 },
    { "/system/lib/libpcre.so", NULL, 0 },
    { "/system/lib/libpng.so", NULL, 0 },
    { "/system/lib/libselinux.so", NULL, 0 },
    { "/system/lib/libsqlite.so", NULL, 0 },
    { "/system/lib/libssl.so", NULL, 0 },
    { "/system/lib/libstdc++.so", NULL, 0 },
    { "/system/lib/libz.so", NULL, 0 },
};

struct map_struct framework_tbl[] = {
    { "/system/framework/ext.jar", NULL, 0 },
    { "/system/framework/core-libart.jar", NULL, 0 },

    { "/system/framework/framework-res.apk", NULL, 0 },
    { "/system/framework/framework-smartisanos-res/framework-smartisanos-res.apk", NULL, 0 },

    { "/system/framework/oat/arm64/services.odex", NULL, 0 },
};

struct map_struct app_tbl[] = {
    { "/system/app/webview/webview.apk", NULL, 0 },
 
    //{ "/system/app/GallerySmartisan/GallerySmartisan.apk", NULL, 0 },
    //{ "/system/app/CameraSmartisan/CameraSmartisan.apk", NULL, 0 },

    { "/system/app/SmartisanOSThemeThirdApp/SmartisanOSThemeThirdApp.apk", NULL, 0 },
    //{ "/system/app/SmartisanOSThemeDefault/SmartisanOSThemeDefault.apk", NULL, 0 },
    { "/system/app/SmartisanOSThemeOchikuri/SmartisanOSThemeOchikuri.apk", NULL, 0 }
};

struct map_struct priv_app_tbl[] = {
    //{ "/system/priv-app/MmsSmartisan/MmsSmartisan.apk", NULL, 0 }
};
#endif
