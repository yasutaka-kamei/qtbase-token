begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcolormap.h"
end_include
begin_include
include|#
directive|include
file|"qcolor.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QColormapPrivate
class|class
name|QColormapPrivate
block|{
public|public:
DECL|function|QColormapPrivate
specifier|inline
name|QColormapPrivate
parameter_list|()
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
block|{ }
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|qt_mac_global_map
specifier|static
name|QColormap
modifier|*
name|qt_mac_global_map
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|initialize
name|void
name|QColormap
operator|::
name|initialize
parameter_list|()
block|{
name|qt_mac_global_map
operator|=
operator|new
name|QColormap
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|QColormap
operator|::
name|cleanup
parameter_list|()
block|{
operator|delete
name|qt_mac_global_map
expr_stmt|;
name|qt_mac_global_map
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|instance
name|QColormap
name|QColormap
operator|::
name|instance
parameter_list|(
name|int
parameter_list|)
block|{
return|return
operator|*
name|qt_mac_global_map
return|;
block|}
end_function
begin_constructor
DECL|function|QColormap
name|QColormap
operator|::
name|QColormap
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QColormapPrivate
argument_list|)
block|{}
end_constructor
begin_constructor
DECL|function|QColormap
name|QColormap
operator|::
name|QColormap
parameter_list|(
specifier|const
name|QColormap
modifier|&
name|colormap
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|colormap
operator|.
name|d
argument_list|)
block|{
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_destructor
DECL|function|~QColormap
name|QColormap
operator|::
name|~
name|QColormap
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|mode
name|QColormap
operator|::
name|Mode
name|QColormap
operator|::
name|mode
parameter_list|()
specifier|const
block|{
return|return
name|QColormap
operator|::
name|Direct
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QColormap
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
literal|32
return|;
block|}
end_function
begin_function
DECL|function|size
name|int
name|QColormap
operator|::
name|size
parameter_list|()
specifier|const
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|pixel
name|uint
name|QColormap
operator|::
name|pixel
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
specifier|const
block|{
return|return
name|color
operator|.
name|rgba
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|colorAt
specifier|const
name|QColor
name|QColormap
operator|::
name|colorAt
parameter_list|(
name|uint
name|pixel
parameter_list|)
specifier|const
block|{
return|return
name|QColor
argument_list|(
name|pixel
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|colormap
specifier|const
name|QVector
argument_list|<
name|QColor
argument_list|>
name|QColormap
operator|::
name|colormap
parameter_list|()
specifier|const
block|{
return|return
name|QVector
argument_list|<
name|QColor
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator =
name|QColormap
modifier|&
name|QColormap
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QColormap
modifier|&
name|colormap
parameter_list|)
block|{
name|qAtomicAssign
argument_list|(
name|d
argument_list|,
name|colormap
operator|.
name|d
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
