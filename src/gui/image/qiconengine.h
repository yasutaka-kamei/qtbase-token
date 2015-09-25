begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QICONENGINE_H
end_ifndef
begin_define
DECL|macro|QICONENGINE_H
define|#
directive|define
name|QICONENGINE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qicon.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QIconEngine
block|{
name|public
label|:
name|QIconEngine
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QIconEngine
argument_list|()
expr_stmt|;
name|virtual
name|void
name|paint
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
name|QIcon
operator|::
name|Mode
name|mode
argument_list|,
name|QIcon
operator|::
name|State
name|state
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|QSize
name|actualSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|QIcon
operator|::
name|Mode
name|mode
argument_list|,
name|QIcon
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
name|virtual
name|QPixmap
name|pixmap
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|QIcon
operator|::
name|Mode
name|mode
argument_list|,
name|QIcon
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
name|virtual
name|void
name|addPixmap
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
name|QIcon
operator|::
name|Mode
name|mode
argument_list|,
name|QIcon
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
name|virtual
name|void
name|addFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|QIcon
operator|::
name|Mode
name|mode
argument_list|,
name|QIcon
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
name|virtual
name|QString
name|key
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QIconEngine
operator|*
name|clone
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|read
parameter_list|(
name|QDataStream
modifier|&
name|in
parameter_list|)
function_decl|;
name|virtual
name|bool
name|write
argument_list|(
name|QDataStream
operator|&
name|out
argument_list|)
decl|const
decl_stmt|;
enum|enum
name|IconEngineHook
block|{
name|AvailableSizesHook
init|=
literal|1
block|,
name|IconNameHook
block|,
name|IsNullHook
block|}
enum|;
struct|struct
name|AvailableSizesArgument
block|{
name|QIcon
operator|::
name|Mode
name|mode
expr_stmt|;
name|QIcon
operator|::
name|State
name|state
expr_stmt|;
name|QList
operator|<
name|QSize
operator|>
name|sizes
expr_stmt|;
block|}
struct|;
name|virtual
name|QList
operator|<
name|QSize
operator|>
name|availableSizes
argument_list|(
argument|QIcon::Mode mode = QIcon::Normal
argument_list|,
argument|QIcon::State state = QIcon::Off
argument_list|)
specifier|const
expr_stmt|;
name|virtual
name|QString
name|iconName
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
comment|// ### Qt6 make virtual
name|virtual
name|void
name|virtual_hook
parameter_list|(
name|int
name|id
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
end_if
begin_typedef
DECL|typedef|QIconEngineV2
typedef|typedef
name|QIconEngine
name|QIconEngineV2
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QICONENGINE_H
end_comment
end_unit
