begin_unit
begin_comment
comment|/* * Copyright (C) 2015 The Qt Company Ltd. * Copyright (C) 2015 Konstantin Ritt * * Permission is hereby granted, without written agreement and without * license or royalty fees, to use, copy, modify, and distribute this * software and its documentation for any purpose, provided that the * above copyright notice and the following two paragraphs appear in * all copies of this software. * * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH * DAMAGE. * * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS. * */
end_comment
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_decl_stmt
name|QT_USE_NAMESPACE
name|namespace
block|{
comment|// We need to cast hb_atomic_int_t to QAtomicInt and pointers to
comment|// QAtomicPointer instead of using QAtomicOps, otherwise we get a failed
comment|// overload resolution of the template arguments for testAndSetOrdered.
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|QAtomicPointer
operator|<
name|T
operator|>
operator|*
name|makeAtomicPointer
argument_list|(
argument|T * const&ptr
argument_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|QAtomicPointer
operator|<
name|T
operator|>
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|T
operator|*
operator|*
operator|>
operator|(
operator|&
name|ptr
operator|)
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_comment
comment|// namespace
end_comment
begin_typedef
DECL|typedef|hb_atomic_int_impl_t
typedef|typedef
name|int
name|hb_atomic_int_impl_t
typedef|;
end_typedef
begin_define
DECL|macro|HB_ATOMIC_INT_IMPL_INIT
define|#
directive|define
name|HB_ATOMIC_INT_IMPL_INIT
parameter_list|(
name|V
parameter_list|)
value|(V)
end_define
begin_define
DECL|macro|hb_atomic_int_impl_add
define|#
directive|define
name|hb_atomic_int_impl_add
parameter_list|(
name|AI
parameter_list|,
name|V
parameter_list|)
value|reinterpret_cast<QAtomicInt&>(AI).fetchAndAddOrdered(V)
end_define
begin_define
DECL|macro|hb_atomic_ptr_impl_get
define|#
directive|define
name|hb_atomic_ptr_impl_get
parameter_list|(
name|P
parameter_list|)
value|makeAtomicPointer(*(P))->loadAcquire()
end_define
begin_define
DECL|macro|hb_atomic_ptr_impl_cmpexch
define|#
directive|define
name|hb_atomic_ptr_impl_cmpexch
parameter_list|(
name|P
parameter_list|,
name|O
parameter_list|,
name|N
parameter_list|)
value|makeAtomicPointer(*(P))->testAndSetOrdered((O), (N))
end_define
end_unit
