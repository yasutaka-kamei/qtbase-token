begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINRTMESSAGEDIALOGHELPER_H
end_ifndef
begin_define
DECL|macro|QWINRTMESSAGEDIALOGHELPER_H
define|#
directive|define
name|QWINRTMESSAGEDIALOGHELPER_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformdialoghelper.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_decl_stmt
name|namespace
name|ABI
block|{
name|namespace
name|Windows
block|{
name|namespace
name|UI
block|{
name|namespace
name|Popups
block|{
struct_decl|struct
name|IUICommand
struct_decl|;
block|}
block|}
name|namespace
name|Foundation
block|{
name|enum
name|class
name|AsyncStatus
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|IAsyncOperation
expr_stmt|;
block|}
block|}
block|}
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWinRTTheme
name|class
name|QWinRTTheme
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWinRTMessageDialogHelperPrivate
name|class
name|QWinRTMessageDialogHelperPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWinRTMessageDialogHelper
range|:
name|public
name|QPlatformMessageDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QWinRTMessageDialogHelper
argument_list|(
specifier|const
name|QWinRTTheme
operator|*
name|theme
argument_list|)
block|;
operator|~
name|QWinRTMessageDialogHelper
argument_list|()
block|;
name|void
name|exec
argument_list|()
block|;
name|bool
name|show
argument_list|(
argument|Qt::WindowFlags windowFlags
argument_list|,
argument|Qt::WindowModality windowModality
argument_list|,
argument|QWindow *parent
argument_list|)
block|;
name|void
name|hide
argument_list|()
block|;
name|private
operator|:
name|HRESULT
name|onCompleted
argument_list|(
argument|ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand *> *asyncInfo
argument_list|,
argument|ABI::Windows::Foundation::AsyncStatus status
argument_list|)
block|;
name|QScopedPointer
operator|<
name|QWinRTMessageDialogHelperPrivate
operator|>
name|d_ptr
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWinRTMessageDialogHelper
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINRTMESSAGEDIALOGHELPER_H
end_comment
end_unit
