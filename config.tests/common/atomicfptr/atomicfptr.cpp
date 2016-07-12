begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Intel Corporation. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the FOO module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<atomic>
end_include
begin_typedef
DECL|typedef|fptr
typedef|typedef
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|atomicfptr
typedef|typedef
name|std
operator|::
name|atomic
argument_list|<
name|fptr
argument_list|>
name|atomicfptr
typedef|;
end_typedef
begin_function
DECL|function|testfunction
name|void
name|testfunction
parameter_list|(
name|int
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|test
name|void
name|test
parameter_list|(
specifier|volatile
name|atomicfptr
modifier|&
name|a
parameter_list|)
block|{
name|fptr
name|v
init|=
name|a
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_acquire
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|a
operator|.
name|compare_exchange_strong
argument_list|(
name|v
argument_list|,
operator|&
name|testfunction
argument_list|,
name|std
operator|::
name|memory_order_acq_rel
argument_list|,
name|std
operator|::
name|memory_order_acquire
argument_list|)
condition|)
block|{
name|v
operator|=
name|a
operator|.
name|exchange
argument_list|(
operator|&
name|testfunction
argument_list|)
expr_stmt|;
block|}
name|a
operator|.
name|store
argument_list|(
operator|&
name|testfunction
argument_list|,
name|std
operator|::
name|memory_order_release
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
block|{
name|atomicfptr
name|fptr
argument_list|(
name|testfunction
argument_list|)
decl_stmt|;
name|test
argument_list|(
name|fptr
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit