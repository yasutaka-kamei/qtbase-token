begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpaintdevice.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|"qwidget.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|<private/qt_x11_p.h>
end_include
begin_include
include|#
directive|include
file|"qx11info_x11.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*! \internal      Returns the X11 Drawable of the paint device. 0 is returned if it     can't be obtained. */
DECL|function|qt_x11Handle
name|Drawable
name|Q_WIDGETS_EXPORT
name|qt_x11Handle
parameter_list|(
specifier|const
name|QPaintDevice
modifier|*
name|pd
parameter_list|)
block|{
if|if
condition|(
operator|!
name|pd
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|pd
operator|->
name|devType
argument_list|()
operator|==
name|QInternal
operator|::
name|Widget
condition|)
return|return
cast|static_cast
argument_list|<
specifier|const
name|QWidget
operator|*
argument_list|>
argument_list|(
name|pd
argument_list|)
operator|->
name|handle
argument_list|()
return|;
elseif|else
if|if
condition|(
name|pd
operator|->
name|devType
argument_list|()
operator|==
name|QInternal
operator|::
name|Pixmap
condition|)
return|return
cast|static_cast
argument_list|<
specifier|const
name|QPixmap
operator|*
argument_list|>
argument_list|(
name|pd
argument_list|)
operator|->
name|handle
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \relates QPaintDevice      Returns the QX11Info structure for the \a pd paint device. 0 is     returned if it can't be obtained. */
end_comment
begin_function
DECL|function|qt_x11Info
specifier|const
name|Q_WIDGETS_EXPORT
name|QX11Info
modifier|*
name|qt_x11Info
parameter_list|(
specifier|const
name|QPaintDevice
modifier|*
name|pd
parameter_list|)
block|{
if|if
condition|(
operator|!
name|pd
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|pd
operator|->
name|devType
argument_list|()
operator|==
name|QInternal
operator|::
name|Widget
condition|)
return|return
operator|&
cast|static_cast
argument_list|<
specifier|const
name|QWidget
operator|*
argument_list|>
argument_list|(
name|pd
argument_list|)
operator|->
name|x11Info
argument_list|()
return|;
elseif|else
if|if
condition|(
name|pd
operator|->
name|devType
argument_list|()
operator|==
name|QInternal
operator|::
name|Pixmap
condition|)
return|return
operator|&
cast|static_cast
argument_list|<
specifier|const
name|QPixmap
operator|*
argument_list|>
argument_list|(
name|pd
argument_list|)
operator|->
name|x11Info
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
