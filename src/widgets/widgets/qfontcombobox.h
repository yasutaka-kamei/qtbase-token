begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTCOMBOBOX_H
end_ifndef
begin_define
DECL|macro|QFONTCOMBOBOX_H
define|#
directive|define
name|QFONTCOMBOBOX_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qcombobox.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfontdatabase.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FONTCOMBOBOX
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFontComboBoxPrivate
name|class
name|QFontComboBoxPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QFontComboBox
range|:
name|public
name|QComboBox
block|{
name|Q_OBJECT
name|Q_FLAGS
argument_list|(
argument|FontFilters
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QFontDatabase::WritingSystem writingSystem READ writingSystem WRITE setWritingSystem
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|FontFilters fontFilters READ fontFilters WRITE setFontFilters
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QFont currentFont READ currentFont WRITE setCurrentFont NOTIFY currentFontChanged
argument_list|)
name|public
operator|:
name|explicit
name|QFontComboBox
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QFontComboBox
argument_list|()
block|;
name|void
name|setWritingSystem
argument_list|(
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|)
block|;
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystem
argument_list|()
specifier|const
block|;      enum
name|FontFilter
block|{
name|AllFonts
operator|=
literal|0
block|,
name|ScalableFonts
operator|=
literal|0x1
block|,
name|NonScalableFonts
operator|=
literal|0x2
block|,
name|MonospacedFonts
operator|=
literal|0x4
block|,
name|ProportionalFonts
operator|=
literal|0x8
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|FontFilters
argument_list|,
argument|FontFilter
argument_list|)
name|void
name|setFontFilters
argument_list|(
argument|FontFilters filters
argument_list|)
block|;
name|FontFilters
name|fontFilters
argument_list|()
specifier|const
block|;
name|QFont
name|currentFont
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setCurrentFont
argument_list|(
specifier|const
name|QFont
operator|&
name|f
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|currentFontChanged
argument_list|(
specifier|const
name|QFont
operator|&
name|f
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QFontComboBox
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFontComboBox
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_currentChanged(const QString&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateModel()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QFontComboBox::FontFilters
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FONTCOMBOBOX
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
