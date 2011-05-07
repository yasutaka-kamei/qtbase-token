begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QFSCompleter
range|:
name|public
name|QCompleter
block|{
name|public
operator|:
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
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
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
block|;
name|QStringList
name|splitPath
argument_list|(
argument|const QString& path
argument_list|)
specifier|const
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
