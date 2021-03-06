#ifndef _MAPLOCK_H
#define _MAPLOCK_H

struct map_struct
{
   const char *path;
   void  *addr;
   size_t length;
};

struct map_struct native_table[] = {
    //arm64
    { "/system/bin/app_process64", NULL, 0 },
    { "/system/bin/linker64", NULL, 0 },
    { "/system/bin/surfaceflinger", NULL, 0 },
    { "/system/bin/toolbox", NULL, 0 },
    { "/system/bin/toybox", NULL, 0 },

    { "/system/lib64/libandroid.so", NULL, 0 },
    { "/system/lib64/libandroid_runtime.so", NULL, 0 },
    { "/system/lib64/libart.so", NULL, 0 },
    { "/system/lib64/libbinder.so", NULL, 0 },
    { "/system/lib64/libc.so", NULL, 0 },
    { "/system/lib64/libcutils.so", NULL, 0 },
    { "/system/lib64/libgui.so", NULL, 0 },
    { "/system/lib64/libhwui.so", NULL, 0 },
    { "/system/lib64/libjpeg.so", NULL, 0 },
    { "/system/lib64/libm.so", NULL, 0 },
    { "/system/lib64/libpng.so", NULL, 0 },
    { "/system/lib64/libskia.so", NULL, 0 },
    { "/system/lib64/libsurfaceflinger.so", NULL, 0 },
    { "/system/lib64/libui.so", NULL, 0 },
    { "/system/lib64/libutils.so", NULL, 0 },
    { "/system/lib64/libz.so", NULL, 0 },

    //arm64-vendor

    //arm32
    { "/system/bin/app_process32", NULL, 0 },
    { "/system/bin/linker", NULL, 0 }
};

struct map_struct framework_table[] = {
    //{ "/system/framework/ext.jar", NULL, 0 },
    { "/system/framework/core-libart.jar", NULL, 0 },

    { "/system/framework/framework-res.apk", NULL, 0 },
    { "/system/framework/framework-smartisanos-res/framework-smartisanos-res.apk", NULL, 0 },

    { "/system/framework/oat/arm64/services.odex", NULL, 0 },

    { "/system/framework/oat/arm/org.simalliance.openmobileapi.odex", NULL, 0 }
};

struct map_struct app_table[] = {
    //{ "/system/app/webview/webview.apk", NULL, 0 },
    { "/system/app/webview/oat/arm/webview.odex", NULL, 0 },

    { "/system/app/SmartisanOSThemeThirdApp/SmartisanOSThemeThirdApp.apk", NULL, 0 },
    { "/system/app/SmartisanOSThemeOchikuri/SmartisanOSThemeOchikuri.apk", NULL, 0 }
};

struct map_struct priv_app_table[] = {
};
#endif
