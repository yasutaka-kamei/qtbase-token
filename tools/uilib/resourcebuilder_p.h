begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the Qt Designer of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|RESOURCEBUILDER_H
end_ifndef
begin_define
DECL|macro|RESOURCEBUILDER_H
define|#
directive|define
name|RESOURCEBUILDER_H
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
file|"uilib_global.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDir
name|class
name|QDir
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QFORMINTERNAL_NAMESPACE
end_ifdef
begin_decl_stmt
name|namespace
name|QFormInternal
block|{
endif|#
directive|endif
name|class
name|DomProperty
decl_stmt|;
name|class
name|DomResourceIcon
decl_stmt|;
name|class
name|QDESIGNER_UILIB_EXPORT
name|QResourceBuilder
block|{
name|public
label|:
enum|enum
name|IconStateFlags
block|{
name|NormalOff
init|=
literal|0x1
block|,
name|NormalOn
init|=
literal|0x2
block|,
name|DisabledOff
init|=
literal|0x4
block|,
name|DisabledOn
init|=
literal|0x8
block|,
name|ActiveOff
init|=
literal|0x10
block|,
name|ActiveOn
init|=
literal|0x20
block|,
name|SelectedOff
init|=
literal|0x40
block|,
name|SelectedOn
init|=
literal|0x80
block|}
enum|;
name|QResourceBuilder
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QResourceBuilder
argument_list|()
expr_stmt|;
name|virtual
name|QVariant
name|loadResource
argument_list|(
specifier|const
name|QDir
operator|&
name|workingDirectory
argument_list|,
specifier|const
name|DomProperty
operator|*
name|property
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QVariant
name|toNativeValue
argument_list|(
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|DomProperty
modifier|*
name|saveResource
argument_list|(
specifier|const
name|QDir
operator|&
name|workingDirectory
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|isResourceProperty
argument_list|(
specifier|const
name|DomProperty
operator|*
name|p
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|isResourceType
argument_list|(
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|int
name|iconStateFlags
parameter_list|(
specifier|const
name|DomResourceIcon
modifier|*
name|resIcon
parameter_list|)
function_decl|;
block|}
empty_stmt|;
ifdef|#
directive|ifdef
name|QFORMINTERNAL_NAMESPACE
block|}
end_decl_stmt
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
comment|// RESOURCEBUILDER_H
end_comment
end_unit
