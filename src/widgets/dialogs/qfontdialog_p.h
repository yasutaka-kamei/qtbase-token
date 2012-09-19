begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTDIALOG_P_H
end_ifndef
begin_define
DECL|macro|QFONTDIALOG_P_H
define|#
directive|define
name|QFONTDIALOG_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"private/qdialog_p.h"
end_include
begin_include
include|#
directive|include
file|"qfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|"qfontdialog.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformdialoghelper.h>
end_include
begin_include
include|#
directive|include
file|"qsharedpointer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FONTDIALOG
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QBoxLayout
name|class
name|QBoxLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCheckBox
name|class
name|QCheckBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDialogButtonBox
name|class
name|QDialogButtonBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontListView
name|class
name|QFontListView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGroupBox
name|class
name|QGroupBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFontDialogPrivate
range|:
name|public
name|QDialogPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFontDialog
argument_list|)
name|public
operator|:
specifier|inline
name|QFontDialogPrivate
argument_list|()
operator|:
name|writingSystem
argument_list|(
name|QFontDatabase
operator|::
name|Any
argument_list|)
block|,
name|options
argument_list|(
argument|new QFontDialogOptions
argument_list|)
block|{ }
name|QPlatformFontDialogHelper
operator|*
name|platformFontDialogHelper
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|QPlatformFontDialogHelper
operator|*
operator|>
operator|(
name|platformHelper
argument_list|()
operator|)
return|;
block|}
name|void
name|updateFamilies
argument_list|()
block|;
name|void
name|updateStyles
argument_list|()
block|;
name|void
name|updateSizes
argument_list|()
block|;
specifier|static
name|QFont
name|getFont
argument_list|(
argument|bool *ok
argument_list|,
argument|const QFont&initial
argument_list|,
argument|QWidget *parent
argument_list|,
argument|const QString&title
argument_list|,
argument|QFontDialog::FontDialogOptions options
argument_list|)
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|_q_sizeChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|_q_familyHighlighted
argument_list|(
name|int
argument_list|)
block|;
name|void
name|_q_writingSystemHighlighted
argument_list|(
name|int
argument_list|)
block|;
name|void
name|_q_styleHighlighted
argument_list|(
name|int
argument_list|)
block|;
name|void
name|_q_sizeHighlighted
argument_list|(
name|int
argument_list|)
block|;
name|void
name|_q_updateSample
argument_list|()
block|;
name|void
name|updateSampleFont
argument_list|(
specifier|const
name|QFont
operator|&
name|newFont
argument_list|)
block|;
name|void
name|retranslateStrings
argument_list|()
block|;
name|QLabel
operator|*
name|familyAccel
block|;
name|QLineEdit
operator|*
name|familyEdit
block|;
name|QFontListView
operator|*
name|familyList
block|;
name|QLabel
operator|*
name|styleAccel
block|;
name|QLineEdit
operator|*
name|styleEdit
block|;
name|QFontListView
operator|*
name|styleList
block|;
name|QLabel
operator|*
name|sizeAccel
block|;
name|QLineEdit
operator|*
name|sizeEdit
block|;
name|QFontListView
operator|*
name|sizeList
block|;
name|QGroupBox
operator|*
name|effects
block|;
name|QCheckBox
operator|*
name|strikeout
block|;
name|QCheckBox
operator|*
name|underline
block|;
name|QComboBox
operator|*
name|color
block|;
name|QGroupBox
operator|*
name|sample
block|;
name|QLineEdit
operator|*
name|sampleEdit
block|;
name|QLabel
operator|*
name|writingSystemAccel
block|;
name|QComboBox
operator|*
name|writingSystemCombo
block|;
name|QBoxLayout
operator|*
name|buttonLayout
block|;
name|QBoxLayout
operator|*
name|effectsLayout
block|;
name|QBoxLayout
operator|*
name|sampleLayout
block|;
name|QBoxLayout
operator|*
name|sampleEditLayout
block|;
name|QDialogButtonBox
operator|*
name|buttonBox
block|;
name|QFontDatabase
name|fdb
block|;
name|QString
name|family
block|;
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystem
block|;
name|QString
name|style
block|;
name|int
name|size
block|;
name|bool
name|smoothScalable
block|;
name|QFont
name|selectedFont
block|;
name|QSharedPointer
operator|<
name|QFontDialogOptions
operator|>
name|options
block|;
name|QPointer
operator|<
name|QObject
operator|>
name|receiverToDisconnectOnClose
block|;
name|QByteArray
name|memberToDisconnectOnClose
block|;
name|bool
name|canBeNativeDialog
argument_list|()
specifier|const
block|;
name|void
name|_q_runNativeAppModalPanel
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_WS_MAC
specifier|static
name|void
name|setFont
argument_list|(
name|void
operator|*
name|delegate
argument_list|,
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
specifier|inline
name|void
name|done
argument_list|(
argument|int result
argument_list|)
block|{
name|q_func
argument_list|()
operator|->
name|done
argument_list|(
name|result
argument_list|)
block|; }
specifier|inline
name|QFontDialog
operator|*
name|fontDialog
argument_list|()
block|{
return|return
name|q_func
argument_list|()
return|;
block|}
name|void
operator|*
name|delegate
block|;
name|void
name|closeCocoaFontPanel
argument_list|()
block|;
name|bool
name|setVisible_sys
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|createNSFontPanelDelegate
argument_list|()
block|;
name|bool
name|showCocoaFontPanel
argument_list|()
block|;
name|bool
name|hideCocoaFontPanel
argument_list|()
block|;
specifier|static
name|bool
name|sharedFontPanelAvailable
block|;
endif|#
directive|endif
name|private
operator|:
name|virtual
name|void
name|initHelper
argument_list|(
name|QPlatformDialogHelper
operator|*
argument_list|)
block|;
name|virtual
name|void
name|helperPrepareShow
argument_list|(
name|QPlatformDialogHelper
operator|*
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FONTDIALOG
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTDIALOG_P_H
end_comment
end_unit
