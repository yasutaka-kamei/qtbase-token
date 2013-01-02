begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOLORMAP_H
end_ifndef
begin_define
DECL|macro|QCOLORMAP_H
define|#
directive|define
name|QCOLORMAP_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qrgb.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColormapPrivate
name|class
name|QColormapPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QColormap
block|{
name|public
label|:
enum|enum
name|Mode
block|{
name|Direct
block|,
name|Indexed
block|,
name|Gray
block|}
enum|;
specifier|static
name|void
name|initialize
parameter_list|()
function_decl|;
specifier|static
name|void
name|cleanup
parameter_list|()
function_decl|;
specifier|static
name|QColormap
name|instance
parameter_list|(
name|int
name|screen
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
name|QColormap
argument_list|(
specifier|const
name|QColormap
operator|&
name|colormap
argument_list|)
expr_stmt|;
operator|~
name|QColormap
argument_list|()
expr_stmt|;
name|QColormap
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QColormap
operator|&
name|colormap
operator|)
decl_stmt|;
name|Mode
name|mode
argument_list|()
specifier|const
expr_stmt|;
name|int
name|depth
argument_list|()
specifier|const
expr_stmt|;
name|int
name|size
argument_list|()
specifier|const
expr_stmt|;
name|uint
name|pixel
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|QColor
name|colorAt
argument_list|(
name|uint
name|pixel
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|QVector
operator|<
name|QColor
operator|>
name|colormap
argument_list|()
specifier|const
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_WIN
specifier|static
name|HPALETTE
name|hPal
parameter_list|()
function_decl|;
endif|#
directive|endif
name|private
label|:
name|QColormap
argument_list|()
expr_stmt|;
name|QColormapPrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOLORMAP_H
end_comment
end_unit
