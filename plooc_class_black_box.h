/****************************************************************************
*  Copyright 2017 Gorgon Meducer (Email:embedded_zhuoran@hotmail.com)       *
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



/*============================ INCLUDES ======================================*/
#include <stdint.h>
#include <stdbool.h>

/*============================ MACROS ========================================*/
#undef def_class
#undef __def_class
#undef end_def_class
#undef __end_def_class
#undef extern_class
#undef __extern_class
#undef end_extern_class
#undef __end_extern_class
#undef class
#undef __class
/*============================ MACROFIED FUNCTIONS ===========================*/

#if   defined(__PLOOC_CLASS_IMPLEMENT)

#   ifdef __OOC_DEBUG__
#       define __def_class(__NAME, __PUBLIC ,...)                               \
    typedef struct __NAME __NAME;                                               \
    typedef struct __##__NAME __##__NAME;                                       \
    struct __##__NAME {                                                         \
        __PUBLIC                                                                \
        PLOOC_VISIBLE(__VA_ARGS__)                                              \
    };                                                                          \
    struct __NAME {                                                             \
        __PUBLIC                                                                \
        PLOOC_VISIBLE(__VA_ARGS__)                                              \
    };                                                                          
#   else
#       define __def_class(__NAME, __PUBLIC, ...)                               \
    typedef struct __NAME __NAME;                                               \
    typedef struct __##__NAME __##__NAME;                                       \
    struct __##__NAME {                                                         \
        __PUBLIC                                                                \
        PLOOC_VISIBLE(__VA_ARGS__)                                              \
    };                                                                          \
    struct __NAME {                                                             \
        __PUBLIC                                                                \
        PLOOC_INVISIBLE(__VA_ARGS__)                                            \
    };                                                                          
    
#   endif
          
#   define __end_def_class(__NAME, ...)                                                                           

#   undef private_member
#   define private_member(...)              PLOOC_VISIBLE(__VA_ARGS__)

#   undef public_member
#   define public_member(...)               PLOOC_VISIBLE(__VA_ARGS__)

#   undef  __class
#   define __class(__NAME)                  __##__NAME

#   undef  class
#   define class(__NAME)                    __class(__NAME)

#define __extern_class(__NAME,...)
#define __end_extern_class(__NAME, ...)

#else

#ifndef __OOC_DEBUG__        

#   define __def_class(__NAME, __PUBLIC, ...)                                   \
    typedef struct __NAME __NAME;                                               \
    typedef struct __##__NAME __##__NAME;                                       \
    struct __##__NAME {                                                         \
        __PUBLIC                                                                \
        PLOOC_VISIBLE(__VA_ARGS__)                                              \
    };                                                                                                                                                  
  
#define __extern_class(__NAME,__PUBLIC, ...)                                    \
    typedef struct __NAME __NAME;                                               \
    struct __NAME {                                                             \
        __PUBLIC                                                                \
        PLOOC_INVISIBLE(__VA_ARGS__)                                            \
    }; 


#define __end_extern_class(__NAME, ...)

#   undef private_member
#   define private_member(...)              PLOOC_VISIBLE(__VA_ARGS__)

#   undef public_member
#   define public_member(...)               PLOOC_VISIBLE(__VA_ARGS__)
    
#else
               
#   define __def_class(__NAME, __PUBLIC, ...)                                   \
    typedef struct __NAME __NAME;                                               \
    typedef struct __##__NAME __##__NAME;                                       \
    struct __##__NAME {                                                         \
        __PUBLIC                                                                \
        PLOOC_VISIBLE(__VA_ARGS__)                                              \
    };                                                                                                                                                  
  
#define __extern_class(__NAME,__PUBLIC, ...)                                    \
    typedef struct __NAME __NAME;                                               \
    struct __NAME {                                                             \
        __PUBLIC                                                                \
        PLOOC_VISIBLE(__VA_ARGS__)                                              \
    }; 


#define __end_extern_class(__NAME, ...)
    
#   undef private_member
#   define private_member(...)              PLOOC_INVISIBLE(__VA_ARGS__)

#   undef public_member
#   define public_member(...)               PLOOC_VISIBLE(__VA_ARGS__)
    
#endif



#   define __end_def_class(__NAME, ...)  

#endif


#   undef  __class
#   define __class(__NAME)                  __##__NAME

#   undef  class
#   define class(__NAME)                    __class(__NAME)

#undef declare_class
#define declare_class(__NAME)           typedef struct __NAME __NAME;  

#define end_def_class(__NAME, ...)      __end_def_class(__NAME, __VA_ARGS__)
#define def_class(__NAME,__PUBLIC, ...)                                         \
            __def_class(__NAME, __PUBLIC, __VA_ARGS__)
#define class(__NAME)                   __class(__NAME)

#define extern_class(__NAME, __PUBLIC, ...)                                     \
            __extern_class(__NAME, __PUBLIC,__VA_ARGS__)
#define end_extern_class(__NAME, ...)   __end_extern_class(__NAME, __VA_ARGS__)

#ifndef __PLOOC_CLASS_BLACK_BOX_H__
#define __PLOOC_CLASS_BLACK_BOX_H__

/*! \brief macro for initializing class in compiler-time
 *! \param __TYPE class name
 *! \param __OBJ target object
 *! \param ... initialization list
 */
#define __INIT_CLASS_OBJ(__TYPE, __OBJ, ...)                                    \
            union {                                                             \
                class(__TYPE) __##__OBJ;                                        \
                __TYPE;                                                         \
            } __OBJ = {                                                         \
                .__##__OBJ = __VA_ARGS__                                        \
            }
#define init_class_obj(__TYPE, __OBJ, ...)                                      \
            __INIT_CLASS_OBJ(__TYPE, __OBJ, __VA_ARGS__)

#define __EXTERN_CLASS_OBJ( __TYPE, __OBJ )                                     \
            extern union {                                                      \
                class(__TYPE) __##__OBJ;                                        \
                __TYPE;                                                         \
            }__OBJ;
#define extern_class_obj(__TYPE, __OBJ)                                         \
            __EXTERN_CLASS_OBJ( __TYPE, __OBJ )
#endif

/*----------------------------------------------------------------------------*          
 * new standard (lower case)                                                  *
 *----------------------------------------------------------------------------*/

#   undef __class_internal
#   define __class_internal(__SRC, __DES, __TYPE, ...)                          \
            class(__TYPE) *(__DES) = (class(__TYPE) *)(__SRC);                  \
            __with_class(__TYPE, (__SRC), __VA_ARGS__)
            
#   undef class_internal
#   define class_internal(__SRC, __DES, __TYPE,...)                             \
            __class_internal(__SRC, __DES, __TYPE, __VA_ARGS__)
            
#   undef __with_class
#   define __with_class(__TYPE, __SRC, ...)                                     \
        {                                                                       \
            class(__TYPE)*_ =(class(__TYPE) *)(__SRC);                          \
            UNUSED_PARAM(_);                                                    \
            __VA_ARGS__;                                                        \
        }                                                                       \
        for (class(__TYPE)*_ =(class(__TYPE) *)(__SRC); NULL != _; _ = NULL)

#   undef with_class
#   define with_class(__TYPE, __SRC, ...)                                       \
            __with_class(__TYPE, __SRC, __VA_ARGS__)                  

        
/*============================ TYPES =========================================*/

/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/

#undef __PLOOC_CLASS_IMPLEMENT
#undef __PLOOC_CLASS_INHERIT
/* EOF */
