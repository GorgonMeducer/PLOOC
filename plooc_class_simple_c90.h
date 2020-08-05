/*****************************************************************************
 *   Copyright(C)2009-2019 by GorgonMeducer<embedded_zhuoran@hotmail.com>    *
 *                       and  SimonQian<simonqian@simonqian.com>             *
 *         with support from  HenryLong<henry_long@163.com>                  *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/


/******************************************************************************
 * HOW TO USE                                                                 *
 ******************************************************************************/
//!Add following content to your module header file, e.g. xxxxxx.h
//#include "plooc_class.h"          

/*============================ INCLUDES ======================================*/
//#include <stdint.h>

/*! \NOTE the uint_fast8_t used in this header file is defined in stdint.h 
          if you don't have stdint.h supported in your toolchain, you should
          define uint_fast8_t all by yourself with following rule:
          a. if the target processor is 8 bits, define it as uint8_t
          b. if the target processor is 16 bits, define it as uint16_t 
          c. if the target processor is 32 bits, define it as uint32_t
          d. if the target processor is 64 bits, define it as either uint32_t or
             uint64_t
 */


#ifdef __cplusplus
extern "C" {
#endif
/*============================ MACROS ========================================*/
#undef private_member
#undef protected_member
#undef public_member


/*============================ MACROFIED FUNCTIONS ===========================*/

#ifndef __PLOOC_CLASS_SIMPLE_C90_H__
#define __PLOOC_CLASS_SIMPLE_C90_H__

#   define __def_simple_class(__name)       struct  __name
#   define def_simple_class(__name)         __def_simple_class(__name)
#   define define_simple_class(__name)      def_simple_class(__name)
#   define declare_simple_class(__name)     typedef struct __name __name;
#   define dcl_simple_class(__name)         declare_simple_class(__name)

#endif  /* __PLOOC_CLASS_SIMPLE_H__ */


#   define private_member(__MEMBER)         __MEMBER
#   define protected_member(__MEMBER)       __MEMBER
#   define public_member(__MEMBER)          __MEMBER



// code below is just try to be compatible with plooc_class_strict
#undef declare_class
#undef dcl_class
#undef def_class
#undef define_class
#undef __def_class
#undef end_def_class
#undef end_define_class
#undef __end_def_class
#undef extern_class
#undef __extern_class
#undef end_extern_class
#undef __end_extern_class

          
#define __end_def_class(__NAME)

#define __def_class(__NAME, __MEMBER)                                           \
    /*typedef struct __NAME __NAME; */                                          \
    struct __NAME {                                                             \
        __MEMBER                                                                \
    };                      
    

#if     defined(__PLOOC_CLASS_IMPLEMENT__) || defined(__PLOOC_CLASS_IMPLEMENT)

#   undef  __class
#   define __class(__NAME)                  __NAME

#   undef  class
#   define class(__NAME)                    __class(__NAME)

            
#   undef __class_internal
#   define __class_internal(__SRC, __DES, __TYPE)                               \
            class(__TYPE) *(__DES) = (class(__TYPE) *)(__SRC);                  
            
#   undef class_internal
#   define class_internal(__SRC, __DES, __TYPE)                                 \
            __class_internal(__SRC, __DES, __TYPE)

#define __extern_class(__NAME, __MEMBER)                                    

#define __end_extern_class(__NAME)
        
#elif   defined(__PLOOC_CLASS_INHERIT__) || defined(__PLOOC_CLASS_INHERIT)

#   undef  __class_protected
#   define __class_protected(__NAME)            __NAME

#   undef  class_protected
#   define class_protected(__NAME)              __class_protected(__NAME)


#   undef __protected_internal
#   define __protected_internal(__SRC, __DES, __TYPE)                           \
            class_protected(__TYPE) *(__DES)=(class_protected(__TYPE) *)(__SRC);

#   undef protected_internal            
#   define protected_internal(__SRC, __DES, __TYPE)                             \
            __protected_internal(__SRC, __DES, __TYPE)                

#define __extern_class(__NAME, __MEMBER)                                    

#define __end_extern_class(__NAME)

#else  /* __PLOOC_CLASS_EXTERN */

#define __extern_class(__NAME, __MEMBER)    __def_class(__NAME, __MEMBER)

#define __end_extern_class(__NAME)

#endif 

#undef which
#define which(__TYPE)                   __TYPE
                                                    
#define def_class(__name, __member)     __def_class(__name, __member)
#define define_class(__name, __member)  def_class(__name, __member)

#define end_def_class(__name)           __end_def_class(__name)
#define end_define_class(__name)        end_def_class(__name)

#define declare_class(__name)           typedef struct __name __name;
#define dcl_class(__name)               declare_class(__name)

#define extern_class(__name, __member)  __extern_class(__name, __member)

#define end_extern_class(__name)        __end_extern_class(__name)

#undef __PLOOC_CLASS_IMPLEMENT__
#undef __PLOOC_CLASS_INHERIT__
#undef __PLOOC_CLASS_IMPLEMENT
#undef __PLOOC_CLASS_INHERIT

/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/

#ifdef __cplusplus
}
#endif
