## PLOOC (Protected Low-overhead Object Oriented programming with ANSI-C)

### Introduction
---
The Protected Low-overhead Object Oriented Programming with ANSI-C, a.k.a PLOOC ['plu:k] is a well-ploished C macro templates which:

* Provide __protection for private__ class members

> NOTE: The protection can be disabled by defining macro __\_\_OOC_DEBUG\_\___ to facilitate debug.

* Support __protected__ members
* Support __multiple inheritance__ 
* Support interface implemetation
* Support strict type checking/validation in certain compilers, such as IAR with multi-file compilation enabled.
* Compliant with __ANSI-C99__ 
* Low-overhead
> NOTE: Almost ZERO OVERHEAD. The template fully utilises the ANSI-C enforce compilation rules to deliver desired OO feature with the necessary cost.

### Update Log
---
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
In order to show how PLOOC is easy and simple to use, examples are provided to show deferent aspects of the new OOPC method. Currently, the available examples are:

- byte_queue
- enhanced_byte_queue
 
More examples will be added later...

### Example 1: byte_queue
This example shows
- How to define a class
    - How to add private member
    - How to add protected member
- How to access class members
- How to define user friendly interface

### Example 2: enhanced_byte_queue
- How to inherit from a base class
    - How to access protected members which are inherited from base
- How to inherit a interface


