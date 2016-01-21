begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Intel Corporation. ** ** Permission is hereby granted, free of charge, to any person obtaining a copy ** of this software and associated documentation files (the "Software"), to deal ** in the Software without restriction, including without limitation the rights ** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell ** copies of the Software, and to permit persons to whom the Software is ** furnished to do so, subject to the following conditions: ** ** The above copyright notice and this permission notice shall be included in ** all copies or substantial portions of the Software. ** ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, ** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE ** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER ** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, ** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN ** THE SOFTWARE. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FFD_ATOMIC_GCC_H
end_ifndef
begin_define
DECL|macro|FFD_ATOMIC_GCC_H
define|#
directive|define
name|FFD_ATOMIC_GCC_H
end_define
begin_comment
comment|/* atomics */
end_comment
begin_comment
comment|/* we'll use the GCC 4.7 atomic builtins  * See http://gcc.gnu.org/onlinedocs/gcc/_005f_005fatomic-Builtins.html#_005f_005fatomic-Builtins  * Or in texinfo: C Extensions> __atomic Builtins  */
end_comment
begin_typedef
DECL|typedef|ffd_atomic_int
typedef|typedef
name|int
name|ffd_atomic_int
typedef|;
end_typedef
begin_define
DECL|macro|ffd_atomic_pointer
define|#
directive|define
name|ffd_atomic_pointer
parameter_list|(
name|type
parameter_list|)
value|type*
end_define
begin_define
DECL|macro|FFD_ATOMIC_INIT
define|#
directive|define
name|FFD_ATOMIC_INIT
parameter_list|(
name|val
parameter_list|)
value|(val)
end_define
begin_define
DECL|macro|FFD_ATOMIC_RELAXED
define|#
directive|define
name|FFD_ATOMIC_RELAXED
value|__ATOMIC_RELAXED
end_define
begin_define
DECL|macro|FFD_ATOMIC_ACQUIRE
define|#
directive|define
name|FFD_ATOMIC_ACQUIRE
value|__ATOMIC_ACQUIRE
end_define
begin_define
DECL|macro|FFD_ATOMIC_RELEASE
define|#
directive|define
name|FFD_ATOMIC_RELEASE
value|__ATOMIC_RELEASE
end_define
begin_comment
comment|// acq_rel& cst not necessary
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
expr|\
operator|(
operator|(
name|__GNUC__
operator|-
literal|0
operator|)
operator|*
literal|100
operator|+
operator|(
name|__GNUC_MINOR__
operator|-
literal|0
operator|)
operator|)
operator|<
literal|407
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
operator|&&
name|__INTEL_COMPILER
operator|-
literal|0
operator|<
literal|1310
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|&&
operator|(
operator|(
name|__clang_major__
operator|-
literal|0
operator|)
operator|*
literal|100
operator|+
operator|(
name|__clang_minor
operator|-
literal|0
operator|)
operator|)
operator|<
literal|303
operator|)
end_if
begin_define
DECL|macro|ffd_atomic_load_n
define|#
directive|define
name|ffd_atomic_load_n
parameter_list|(
name|ptr
parameter_list|,
name|order
parameter_list|)
value|*(ptr)
end_define
begin_define
DECL|macro|ffd_atomic_store_n
define|#
directive|define
name|ffd_atomic_store_n
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|,
name|order
parameter_list|)
value|(*(ptr) = (val), (void)0)
end_define
begin_define
DECL|macro|ffd_atomic_exchange_n
define|#
directive|define
name|ffd_atomic_exchange_n
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|,
name|order
parameter_list|)
value|__sync_lock_test_and_set(ptr, val)
end_define
begin_define
DECL|macro|ffd_atomic_compare_exchange_n
define|#
directive|define
name|ffd_atomic_compare_exchange_n
parameter_list|(
name|ptr
parameter_list|,
name|expected
parameter_list|,
name|desired
parameter_list|,
name|weak
parameter_list|,
name|order1
parameter_list|,
name|order2
parameter_list|)
define|\
value|__sync_bool_compare_and_swap(ptr, *(expected), desired) ? 1 : \     (*(expected) = *(ptr), 0)
end_define
begin_define
DECL|macro|ffd_atomic_add_fetch
define|#
directive|define
name|ffd_atomic_add_fetch
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|,
name|order
parameter_list|)
value|__sync_add_and_fetch(ptr, val)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|ffd_atomic_load
define|#
directive|define
name|ffd_atomic_load
parameter_list|(
name|ptr
parameter_list|,
name|order
parameter_list|)
value|__atomic_load_n(ptr, order)
end_define
begin_define
DECL|macro|ffd_atomic_store
define|#
directive|define
name|ffd_atomic_store
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|,
name|order
parameter_list|)
value|__atomic_store_n(ptr, val, order)
end_define
begin_define
DECL|macro|ffd_atomic_exchange
define|#
directive|define
name|ffd_atomic_exchange
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|,
name|order
parameter_list|)
value|__atomic_exchange_n(ptr, val, order)
end_define
begin_define
DECL|macro|ffd_atomic_compare_exchange
define|#
directive|define
name|ffd_atomic_compare_exchange
parameter_list|(
name|ptr
parameter_list|,
name|expected
parameter_list|,
name|desired
parameter_list|,
name|order1
parameter_list|,
name|order2
parameter_list|)
define|\
value|__atomic_compare_exchange_n(ptr, expected, desired, 1, order1, order2)
end_define
begin_define
DECL|macro|ffd_atomic_add_fetch
define|#
directive|define
name|ffd_atomic_add_fetch
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|,
name|order
parameter_list|)
value|__atomic_add_fetch(ptr, val, order)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
