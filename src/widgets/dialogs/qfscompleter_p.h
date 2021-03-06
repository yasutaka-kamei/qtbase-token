begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFSCOMPLETOR_P_H
end_ifndef
begin_define
DECL|macro|QFSCOMPLETOR_P_H
define|#
directive|define
name|QFSCOMPLETOR_P_H
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
begin_include
include|#
directive|include
file|"qcompleter.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qfilesystemmodel.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_FSCOMPLETER
comment|/*!     QCompleter that can deal with QFileSystemModel   */
name|class
name|Q_WIDGETS_EXPORT
name|QFSCompleter
range|:
name|public
name|QCompleter
block|{
name|public
operator|:
name|explicit
name|QFSCompleter
argument_list|(
name|QFileSystemModel
operator|*
name|model
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QCompleter
argument_list|(
name|model
argument_list|,
name|parent
argument_list|)
block|,
name|proxyModel
argument_list|(
literal|0
argument_list|)
block|,
name|sourceModel
argument_list|(
argument|model
argument_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|setCaseSensitivity
argument_list|(
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
block|;
endif|#
directive|endif
block|}
name|QString
name|pathFromIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|splitPath
argument_list|(
argument|const QString& path
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QAbstractProxyModel
operator|*
name|proxyModel
block|;
name|QFileSystemModel
operator|*
name|sourceModel
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FSCOMPLETER
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFSCOMPLETOR_P_H
end_comment
end_unit
