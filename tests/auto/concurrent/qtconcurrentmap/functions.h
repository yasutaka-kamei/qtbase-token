begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FUNCTIONS_H
end_ifndef
begin_define
DECL|macro|FUNCTIONS_H
define|#
directive|define
name|FUNCTIONS_H
end_define
begin_function
DECL|function|keepEvenIntegers
name|bool
name|keepEvenIntegers
parameter_list|(
specifier|const
name|int
modifier|&
name|x
parameter_list|)
block|{
return|return
operator|(
name|x
operator|&
literal|1
operator|)
operator|==
literal|0
return|;
block|}
end_function
begin_decl_stmt
name|class
name|KeepEvenIntegers
block|{
name|public
label|:
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|int
operator|&
name|x
operator|)
block|{
return|return
operator|(
name|x
operator|&
literal|1
operator|)
operator|==
literal|0
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Number
block|{
name|int
name|n
decl_stmt|;
name|public
label|:
name|Number
argument_list|()
operator|:
name|n
argument_list|(
literal|0
argument_list|)
block|{ }
name|Number
argument_list|(
argument|int n
argument_list|)
operator|:
name|n
argument_list|(
argument|n
argument_list|)
block|{ }
name|void
name|multiplyBy2
argument_list|()
block|{
name|n
operator|*=
literal|2
block|;     }
name|Number
name|multipliedBy2
argument_list|()
specifier|const
block|{
return|return
name|n
operator|*
literal|2
return|;
block|}
name|bool
name|isEven
argument_list|()
specifier|const
block|{
return|return
operator|(
name|n
operator|&
literal|1
operator|)
operator|==
literal|0
return|;
block|}
name|int
name|toInt
argument_list|()
specifier|const
block|{
return|return
name|n
return|;
block|}
name|QString
name|toString
argument_list|()
specifier|const
block|{
return|return
name|QString
operator|::
name|number
argument_list|(
name|n
argument_list|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Number
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|n
operator|==
name|other
operator|.
name|n
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function
DECL|function|intSumReduce
name|void
name|intSumReduce
parameter_list|(
name|int
modifier|&
name|sum
parameter_list|,
name|int
name|x
parameter_list|)
block|{
name|sum
operator|+=
name|x
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|class
name|IntSumReduce
block|{
name|public
label|:
name|void
name|operator
argument_list|()
operator|(
name|int
operator|&
name|sum
operator|,
name|int
name|x
operator|)
block|{
name|sum
operator|+=
name|x
block|;     }
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function
DECL|function|numberSumReduce
name|void
name|numberSumReduce
parameter_list|(
name|int
modifier|&
name|sum
parameter_list|,
specifier|const
name|Number
modifier|&
name|x
parameter_list|)
block|{
name|sum
operator|+=
name|x
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|class
name|NumberSumReduce
block|{
name|public
label|:
name|void
name|operator
argument_list|()
operator|(
name|int
operator|&
name|sum
operator|,
specifier|const
name|Number
operator|&
name|x
operator|)
block|{
name|sum
operator|+=
name|x
operator|.
name|toInt
argument_list|()
block|;     }
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
