## PLOOC (Protected Low-overhead Object Oriented programming with ANSI-C)

### Introduction
---
The Protected Low-overhead Object Oriented Programming with ANSI-C, a.k.a PLOOC ['plu:k] is a well-ploished C macro templates which:

- Provide __protection for private__ class members

> NOTE: The protection can be disabled by defining macro __\_\_OOC_DEBUG\_\___ to facilitate debug.

- Support __protected__ members
- Support __multiple inheritance__ 
- Support interface implemetation
- Support strict type checking/validation in certain compilers, such as IAR with multi-file compilation enabled.
- Compliant with __ANSI-C99__ 
- Low-overhead
> NOTE: Almost ZERO OVERHEAD. The template fully utilises the ANSI-C enforce compilation rules to deliver desired OO feature with the necessary cost.

        - Suitable for both bare-metal and RTOS.
        - Suitable for both 8bit and 32bit MCU

### What makes PLOOC different from other OOCs?
The concept of OOC is not new. There are plenty of libraries, SDKs, templates providing objected-oriented programming extension to ANSI-C language. Although PLOOC emphasizes its low-overhead feature in both code size and performance, but a lot of macro template based ooc solutions are also low-overhead. PLOOC doesn't force you to use heap or pool for memory management, it doesn't provide GC feature. It simply leave those options to users, so it is suitable for even 8bit system. Well, you can take this as draw-backs of PLOOC. I don't want to argue about this.

**So what really set PLOOC different from the others? Is it simply another re-invented wheel?**

The answer is NO. Of course. 
PLOOC brings an unique feature most of others don't have. It let private members of a class truly become private, i.e. protected. So users outside of the class source code are prevented from accessing the private members. What they see will be a solid memory, a mask created with byte array. Since class is mimicked by structure in C, the class in PLOOC is implemented with the masked-structure. As people expected, only class source code can access the private member, only class source code of a derived class can access the protected member of the base class and everyone can accesss the public members.

How could this be? You might already figure it out simply through the word "masked-structure". As you noticed, it could be nothing more than a fancy type-cheating trick in header files. 
The type-cheating trick works well until some strict-type-checking compiler is encoutered, the most famous (notorious) one is IAR with multi-file compilation mode enabled. No type-cheating can survive from the bloody axe of IAR multi-file compilation mode. 

    //! the original structure in class source code
    struct byte_queue_t {
	    uint8_t   *pchBuffer;
	    uint16_t  hwBufferSize;
	    uint16_t  hwHead;
	    uint16_t  hwTail;
	    uint16_t  hwCount;
	};
	
	//! the masked structure: the class byte_queue_t in header file
	typedef struct byte_queue_t {
        uint8_t chMask [sizeof(struct {
	        uint8_t   *pchBuffer;
	        uint16_t  hwBufferSize;
	        uint16_t  hwHead;
	        uint16_t  hwTail;
	        uint16_t  hwCount;
	    })];
	} byte_queue_t;
	
It order to make it work, make sure the class source codes don't include their own interface header file.
you can even do this...if you are serious about the content

	//! the masked structure: the class byte_queue_t in header file
	typedef struct byte_queue_t {
	    uint8_t chMask [sizeof(struct {
            uint32_t        : 32;
            uint16_t        : 16;
            uint16_t        : 16;
            uint16_t        : 16;
            uint16_t        : 16;
        })];
	} byte_queue_t;
	

PLOOC provides the "private-protection" feature with a different scheme other than type-cheating, so it support almost all C compilers with C99 feature enabled. As the author, I have to confess that it took me a lot of time to figure it out how to deal with strict-type-checking and the inital scheme was urgly and counter-intuition. Thanks to SimonQian, it took the team another 3 months to make PLOOC elegent and simple. The support from HenryLong is also vital. 

I hope you can enjoy this unique trying for the object-oriented programming challenge. 

If you have any questions or suggestions, please feel free to let us know.

### Update Log
---

- \[07/26/2019\] Syntax update, version 4.21
    - Modify plooc_class_black_box.h to use unified syntax as other templates.
    - Add extern_class and end_extern_class to all templates

- \[07/24/2019\] Add new ooc class template, version 4.20
    - Add plooc_class_black_box.h. This template is used for creating true-black-box module. It only support "private" and "public" but no "protected".  

- \[07/12/2019\] Minor Update, version 4.13
    - Add "__OOC_RELEASE__". The struct requires protection only at development stage. For private properties, setters and getters are provided for controlloing the access. It is possible to remove masks and allow private members observable in release stage, during this stage, the setters and getters can be changed from API functions to macros. By doing so, the code size can be smaller.

- \[05/30/2019\] Minor Update, version 4.12
    - remove "this", "target" and "base" to prevent naming pollution.
    - remove PLOOC_ALIGN from top-level class definition to prevent inconsistent compiler interpretation towards this alignment decroration. 

- \[05/02/2019\] Efficiency improve, version 4.11
    - Use \_\_alignof\_\_ to improve the code efficiency when dealing with masked structure
    - Use PLOOC_INVISIABLE and PLOOC_VISIBLE in both simple and strict version
    - Simplify the structure
    - Improve capatability between IAR and armclang (LLVM)

- \[05/01/2019\] Compatability Improving, version 4.04
    - Add PLOOC_PACKED and PLOOC_ALIGN to add alignment support
    - Using uint_fast8_t to replace uint8_t to use target machine implied alignment.

- \[04/20/2019\] Upload PLOOC to github, version 4.03
    - Add default class alignment control
    - update examples and readme
    
- \[04/17/2019\] Upload PLOOC to github, version 4.01
    - Add method definition which support private method, protected method and public method
    - Add readme and example byte_queue


### License
---
The PLOOC library was written by GorgonMeducer(王卓然）<embedded_zhuoran@hotmail.com> and Simon Qian（钱晓晨）<https://github.com/versaloon> with support from Henry Long <henry_long@163.com>.

The PLOOC library is released under an open source license Apache 2.0 that allows both commercial and non-commercial use without restrictions. The only requirement is that credits is given in the source code and in the documentation for your product.

The full license text follows:

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


### Contribution
---
#### Template
| module | Contrinutor |
| ------ | ------ |
| plooc.h | GorgonMeducer ||
| plooc_class.h | GorgonMeducer, Simon Qian | 
| plooc_class_strict.h | GorgonMeducer |
| plooc_class_simple.h | Simon Qian |


#### Example
| module | Contrinutor |
| ------ | ------ |
| byte_queue | GorgonMeducer |
| Advanced_byte_queue | GorgonMeducer |

### Applications / Projects which claim to use PLOOC
---
- [VSF][https://github.com/vsfteam/vsf]
- [GMSI][https://github.com/GorgonMeducer/Generic_MCU_Software_Infrastructure]


### How to Use
---
#### Examples for PLOOC
##### Introduction
In order to show how PLOOC is easy and simple to use, examples are provided to demostrate different aspects of the new OOPC method. Currently, the available examples are:

- byte_queue
- enhanced_byte_queue
 
More examples will be added later...

### [Example 1: byte_queue](https://github.com/GorgonMeducer/PLOOC/tree/master/example/byte_queue)
This example shows
- How to define a class
    - How to add private member
    - How to add protected member
- How to access class members
- How to define user friendly interface

### [Example 2: enhanced_byte_queue](https://github.com/GorgonMeducer/PLOOC/tree/master/example/enhanced_byte_queue)
- How to inherit from a base class
    - How to access protected members which are inherited from base
- How to inherit a interface
- How to override base methods


