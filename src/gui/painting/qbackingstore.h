begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBACKINGSTORE_H
end_ifndef
begin_define
DECL|macro|QBACKINGSTORE_H
define|#
directive|define
name|QBACKINGSTORE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qregion.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QRegion
name|class
name|QRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBackingStorePrivate
name|class
name|QBackingStorePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformBackingStore
name|class
name|QPlatformBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QBackingStore
block|{
name|public
label|:
name|explicit
name|QBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
operator|~
name|QBackingStore
argument_list|()
expr_stmt|;
name|QWindow
operator|*
name|window
argument_list|()
specifier|const
expr_stmt|;
name|QPaintDevice
modifier|*
name|paintDevice
parameter_list|()
function_decl|;
comment|// 'window' can be a child window, in which case 'region' is in child window coordinates and
comment|// offset is the (child) window's offset in relation to the window surface.
name|void
name|flush
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
name|QWindow
modifier|*
name|window
init|=
name|Q_NULLPTR
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
init|=
name|QPoint
argument_list|()
parameter_list|)
function_decl|;
name|void
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|QSize
name|size
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
function_decl|;
name|void
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
parameter_list|)
function_decl|;
name|void
name|endPaint
parameter_list|()
function_decl|;
name|void
name|setStaticContents
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
name|QRegion
name|staticContents
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasStaticContents
argument_list|()
specifier|const
expr_stmt|;
name|QPlatformBackingStore
operator|*
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QScopedPointer
operator|<
name|QBackingStorePrivate
operator|>
name|d_ptr
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBACKINGSTORE_H
end_comment
end_unit
