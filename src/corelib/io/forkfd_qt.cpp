begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Intel Corporation ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// these might be defined via precompiled headers
end_comment
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|"qprocess_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QPROCESS_USE_SPAWN
end_ifdef
begin_define
DECL|macro|FORKFD_NO_FORKFD
define|#
directive|define
name|FORKFD_NO_FORKFD
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FORKFD_NO_SPAWNFD
define|#
directive|define
name|FORKFD_NO_SPAWNFD
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NDEBUG
argument_list|)
end_if
begin_define
DECL|macro|NDEBUG
define|#
directive|define
name|NDEBUG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|ffd_atomic_int
typedef|typedef
name|QT_PREPEND_NAMESPACE
argument_list|(
argument|QBasicAtomicInt
argument_list|)
name|ffd_atomic_int
expr_stmt|;
end_typedef
begin_define
DECL|macro|ffd_atomic_pointer
define|#
directive|define
name|ffd_atomic_pointer
parameter_list|(
name|type
parameter_list|)
value|QT_PREPEND_NAMESPACE(QBasicAtomicPointer<type>)
end_define
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|FFD_ATOMIC_INIT
define|#
directive|define
name|FFD_ATOMIC_INIT
parameter_list|(
name|val
parameter_list|)
value|Q_BASIC_ATOMIC_INITIALIZER(val)
DECL|macro|FFD_ATOMIC_RELAXED
define|#
directive|define
name|FFD_ATOMIC_RELAXED
value|Relaxed
DECL|macro|FFD_ATOMIC_ACQUIRE
define|#
directive|define
name|FFD_ATOMIC_ACQUIRE
value|Acquire
DECL|macro|FFD_ATOMIC_RELEASE
define|#
directive|define
name|FFD_ATOMIC_RELEASE
value|Release
DECL|macro|loadRelaxed
define|#
directive|define
name|loadRelaxed
value|load
DECL|macro|storeRelaxed
define|#
directive|define
name|storeRelaxed
value|store
DECL|macro|FFD_CONCAT
define|#
directive|define
name|FFD_CONCAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## y
DECL|macro|ffd_atomic_load
define|#
directive|define
name|ffd_atomic_load
parameter_list|(
name|ptr
parameter_list|,
name|order
parameter_list|)
value|(ptr)->FFD_CONCAT(load, order)()
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
value|(ptr)->FFD_CONCAT(store, order)(val)
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
value|(ptr)->FFD_CONCAT(fetchAndStore, order)(val)
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
value|(ptr)->FFD_CONCAT(testAndSet, order1)(*expected, desired, *expected)
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
value|((ptr)->FFD_CONCAT(fetchAndAdd, order)(val) + val)
name|QT_END_NAMESPACE
decl|extern "C"
argument_list|{
include|#
directive|include
file|"../../3rdparty/forkfd/forkfd.c"
argument_list|}
end_decl_stmt
end_unit
