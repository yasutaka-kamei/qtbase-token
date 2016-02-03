begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSDIALOGHELPER_H
end_ifndef
begin_define
DECL|macro|QWINDOWSDIALOGHELPER_H
define|#
directive|define
name|QWINDOWSDIALOGHELPER_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformdialoghelper.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFileDialog
name|class
name|QFileDialog
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDialog
name|class
name|QDialog
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QThread
name|class
name|QThread
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsNativeDialogBase
name|class
name|QWindowsNativeDialogBase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QWindowsDialogs
block|{
name|void
name|eatMouseMove
parameter_list|()
function_decl|;
name|bool
name|useHelper
argument_list|(
name|QPlatformTheme
operator|::
name|DialogType
name|type
argument_list|)
decl_stmt|;
name|QPlatformDialogHelper
modifier|*
name|createHelper
argument_list|(
name|QPlatformTheme
operator|::
name|DialogType
name|type
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace QWindowsDialogs
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|BaseClass
operator|>
name|class
name|QWindowsDialogHelperBase
operator|:
name|public
name|BaseClass
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsDialogHelperBase
argument_list|)
name|public
operator|:
typedef|typedef
name|QSharedPointer
operator|<
name|QWindowsNativeDialogBase
operator|>
name|QWindowsNativeDialogBasePtr
expr_stmt|;
operator|~
name|QWindowsDialogHelperBase
argument_list|()
block|{
name|cleanupThread
argument_list|()
block|; }
name|void
name|exec
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|show
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|windowFlags
argument_list|,
name|Qt
operator|::
name|WindowModality
name|windowModality
argument_list|,
name|QWindow
operator|*
name|parent
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|void
name|hide
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|virtual
name|bool
name|supportsNonModalDialog
argument_list|(
specifier|const
name|QWindow
operator|*
comment|/* parent */
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
end_decl_stmt
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|QWindowsDialogHelperBase
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QWindowsNativeDialogBase
operator|*
name|nativeDialog
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|hasNativeDialog
argument_list|()
specifier|const
block|{
return|return
name|m_nativeDialog
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_function_decl
name|virtual
name|QWindowsNativeDialogBase
modifier|*
name|createNativeDialog
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl
begin_function_decl
specifier|inline
name|QWindowsNativeDialogBase
modifier|*
name|ensureNativeDialog
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|inline
name|void
name|startDialogThread
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|inline
name|void
name|stopTimer
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|cleanupThread
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|QWindowsNativeDialogBasePtr
name|m_nativeDialog
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|HWND
name|m_ownerWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_timerId
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QThread
modifier|*
name|m_thread
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSDIALOGHELPER_H
end_comment
end_unit
