begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatformdrag.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMimeData>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qdnd_p.h>
end_include
begin_comment
comment|// QInternalMime
end_comment
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_decl_stmt
name|namespace
name|ABI
block|{
name|namespace
name|Windows
block|{
name|namespace
name|ApplicationModel
block|{
name|namespace
name|DataTransfer
block|{
struct_decl|struct
name|IDataPackageView
struct_decl|;
block|}
block|}
name|namespace
name|UI
block|{
name|namespace
name|Xaml
block|{
struct_decl|struct
name|IUIElement
struct_decl|;
struct_decl|struct
name|IDragEventArgs
struct_decl|;
struct_decl|struct
name|IDragOperationDeferral
struct_decl|;
comment|//struct IDataPackageView;
block|}
block|}
block|}
block|}
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
name|lcQpaMime
argument_list|)
name|class
name|QtDragEventHandlerEnter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QtDragEventHandlerOver
name|class
name|QtDragEventHandlerOver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QtDragEventHandlerLeave
name|class
name|QtDragEventHandlerLeave
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QtDragEventHandlerDrop
name|class
name|QtDragEventHandlerDrop
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWinRTInternalMimeData
name|class
name|QWinRTInternalMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWinRTInternalMimeData
range|:
name|public
name|QInternalMimeData
block|{
name|public
operator|:
name|QWinRTInternalMimeData
argument_list|()
block|;
name|virtual
operator|~
name|QWinRTInternalMimeData
argument_list|()
block|;
name|bool
name|hasFormat_sys
argument_list|(
argument|const QString&mimetype
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|formats_sys
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|retrieveData_sys
argument_list|(
argument|const QString&mimetype
argument_list|,
argument|QVariant::Type preferredType
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setDataView
argument_list|(
specifier|const
name|Microsoft
operator|::
name|WRL
operator|::
name|ComPtr
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
operator|::
name|DataTransfer
operator|::
name|IDataPackageView
operator|>
operator|&
name|d
argument_list|)
block|;
name|private
operator|:
name|Microsoft
operator|::
name|WRL
operator|::
name|ComPtr
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
operator|::
name|DataTransfer
operator|::
name|IDataPackageView
operator|>
name|dataView
block|;
name|mutable
name|QStringList
name|formats
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWinRTDrag
range|:
name|public
name|QPlatformDrag
block|{
name|public
operator|:
name|QWinRTDrag
argument_list|()
block|;
name|virtual
operator|~
name|QWinRTDrag
argument_list|()
block|;
specifier|static
name|QWinRTDrag
operator|*
name|instance
argument_list|()
block|;
name|QMimeData
operator|*
name|platformDropData
argument_list|(
argument|void
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|DropAction
name|drag
argument_list|(
argument|QDrag *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setDropTarget
argument_list|(
name|QWindow
operator|*
name|target
argument_list|)
block|;
comment|// Native integration and registration
name|void
name|setUiElement
argument_list|(
name|Microsoft
operator|::
name|WRL
operator|::
name|ComPtr
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Xaml
operator|::
name|IUIElement
operator|>
operator|&
name|element
argument_list|)
block|;
name|void
name|handleNativeDragEvent
argument_list|(
argument|IInspectable *sender
argument_list|,
argument|ABI::Windows::UI::Xaml::IDragEventArgs *e
argument_list|,
argument|bool drop = false
argument_list|)
block|;
name|private
operator|:
name|Microsoft
operator|::
name|WRL
operator|::
name|ComPtr
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Xaml
operator|::
name|IUIElement
operator|>
name|m_ui
block|;
name|QWindow
operator|*
name|m_dragTarget
block|;
name|QtDragEventHandlerEnter
operator|*
name|m_enter
block|;
name|QtDragEventHandlerOver
operator|*
name|m_over
block|;
name|QtDragEventHandlerLeave
operator|*
name|m_leave
block|;
name|QtDragEventHandlerDrop
operator|*
name|m_drop
block|;
name|QWinRTInternalMimeData
operator|*
name|m_mimeData
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
