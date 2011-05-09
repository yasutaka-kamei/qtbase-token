begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWAYLANDCLIPBOARD_H
end_ifndef
begin_define
DECL|macro|QWAYLANDCLIPBOARD_H
define|#
directive|define
name|QWAYLANDCLIPBOARD_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPlatformClipboard>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_decl_stmt
DECL|variable|QWaylandDisplay
name|class
name|QWaylandDisplay
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWaylandSelection
name|class
name|QWaylandSelection
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|wl_selection_offer
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|QWaylandClipboard
range|:
name|public
name|QPlatformClipboard
block|{
name|public
operator|:
name|QWaylandClipboard
argument_list|(
name|QWaylandDisplay
operator|*
name|display
argument_list|)
block|;
operator|~
name|QWaylandClipboard
argument_list|()
block|;
specifier|const
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|QClipboard::Mode mode = QClipboard::Clipboard
argument_list|)
specifier|const
block|;
name|void
name|setMimeData
argument_list|(
argument|QMimeData *data
argument_list|,
argument|QClipboard::Mode mode = QClipboard::Clipboard
argument_list|)
block|;
name|bool
name|supportsMode
argument_list|(
argument|QClipboard::Mode mode
argument_list|)
specifier|const
block|;
name|void
name|unregisterSelection
argument_list|(
name|QWaylandSelection
operator|*
name|selection
argument_list|)
block|;
name|void
name|createSelectionOffer
argument_list|(
argument|uint32_t id
argument_list|)
block|;
name|private
operator|:
specifier|static
name|void
name|offer
argument_list|(
name|void
operator|*
name|data
argument_list|,
expr|struct
name|wl_selection_offer
operator|*
name|selection_offer
argument_list|,
specifier|const
name|char
operator|*
name|type
argument_list|)
block|;
specifier|static
name|void
name|keyboardFocus
argument_list|(
name|void
operator|*
name|data
argument_list|,
expr|struct
name|wl_selection_offer
operator|*
name|selection_offer
argument_list|,
expr|struct
name|wl_input_device
operator|*
name|input_device
argument_list|)
block|;
specifier|static
specifier|const
expr|struct
name|wl_selection_offer_listener
name|selectionOfferListener
block|;
specifier|static
name|void
name|syncCallback
argument_list|(
name|void
operator|*
name|data
argument_list|)
block|;
specifier|static
name|void
name|forceRoundtrip
argument_list|(
expr|struct
name|wl_display
operator|*
name|display
argument_list|)
block|;
name|QWaylandDisplay
operator|*
name|mDisplay
block|;
name|QWaylandSelection
operator|*
name|mSelection
block|;
name|mutable
name|QMimeData
operator|*
name|mMimeDataIn
block|;
name|QList
operator|<
name|QWaylandSelection
operator|*
operator|>
name|mSelections
block|;
name|QStringList
name|mOfferedMimeTypes
block|;     struct
name|wl_selection_offer
operator|*
name|mOffer
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWAYLANDCLIPBOARD_H
end_comment
end_unit
