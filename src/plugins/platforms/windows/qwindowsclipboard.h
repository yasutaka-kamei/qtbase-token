begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSCLIPBOARD_H
end_ifndef
begin_define
DECL|macro|QWINDOWSCLIPBOARD_H
define|#
directive|define
name|QWINDOWSCLIPBOARD_H
end_define
begin_include
include|#
directive|include
file|"qwindowsinternalmimedata.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformclipboard.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsOleDataObject
name|class
name|QWindowsOleDataObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsClipboardRetrievalMimeData
range|:
name|public
name|QWindowsInternalMimeData
block|{
name|public
operator|:
name|protected
operator|:
name|virtual
name|IDataObject
operator|*
name|retrieveDataObject
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|releaseDataObject
argument_list|(
argument|IDataObject *
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsClipboard
range|:
name|public
name|QPlatformClipboard
block|{
name|public
operator|:
name|QWindowsClipboard
argument_list|()
block|;
operator|~
name|QWindowsClipboard
argument_list|()
block|;
name|void
name|registerViewer
argument_list|()
block|;
comment|// Call in initialization, when context is up.
name|virtual
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|QClipboard::Mode mode = QClipboard::Clipboard
argument_list|)
block|;
name|virtual
name|void
name|setMimeData
argument_list|(
argument|QMimeData *data
argument_list|,
argument|QClipboard::Mode mode = QClipboard::Clipboard
argument_list|)
block|;
name|virtual
name|bool
name|supportsMode
argument_list|(
argument|QClipboard::Mode mode
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|ownsMode
argument_list|(
argument|QClipboard::Mode mode
argument_list|)
specifier|const
block|;
specifier|inline
name|bool
name|clipboardViewerWndProc
argument_list|(
argument|HWND hwnd
argument_list|,
argument|UINT message
argument_list|,
argument|WPARAM wParam
argument_list|,
argument|LPARAM lParam
argument_list|,
argument|LRESULT *result
argument_list|)
block|;
specifier|static
name|QWindowsClipboard
operator|*
name|instance
argument_list|()
block|{
return|return
name|m_instance
return|;
block|}
name|private
operator|:
name|void
name|clear
argument_list|()
block|;
name|void
name|releaseIData
argument_list|()
block|;
specifier|inline
name|void
name|propagateClipboardMessage
argument_list|(
argument|UINT message
argument_list|,
argument|WPARAM wParam
argument_list|,
argument|LPARAM lParam
argument_list|)
specifier|const
block|;
specifier|inline
name|void
name|unregisterViewer
argument_list|()
block|;
specifier|inline
name|bool
name|ownsClipboard
argument_list|()
specifier|const
block|;
specifier|static
name|QWindowsClipboard
operator|*
name|m_instance
block|;
name|QWindowsClipboardRetrievalMimeData
name|m_retrievalData
block|;
name|QWindowsOleDataObject
operator|*
name|m_data
block|;
name|HWND
name|m_clipboardViewer
block|;
name|HWND
name|m_nextClipboardViewer
block|; }
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
comment|// QWINDOWSCLIPBOARD_H
end_comment
end_unit
