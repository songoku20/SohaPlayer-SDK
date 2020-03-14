//
//  SHMediaPlayerDefines.h
//  SohaPlayer
//
//  Created by Hung Nguyen on 10/14/16.
//  Copyright © 2016 Hung Nguyen. All rights reserved.
//

#ifdef __cplusplus
#define SH_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define SH_EXTERN     extern __attribute__((visibility ("default")))
#endif

#define SH_EXTERN_CLASS                    __attribute__((visibility("default")))
#define SH_EXTERN_CLASS_AVAILABLE(version) __attribute__((visibility("default"))) NS_CLASS_AVAILABLE(NA, version)
