begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfreelist_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// default sizes and offsets (no need to define these when customizing)
name|enum
type|{
DECL|enumerator|Offset0
name|Offset0
init|=
literal|0x00000000
decl_stmt|,
DECL|enumerator|Offset1
name|Offset1
init|=
literal|0x00008000
decl_stmt|,
DECL|enumerator|Offset2
name|Offset2
init|=
literal|0x00080000
decl_stmt|,
DECL|enumerator|Offset3
name|Offset3
init|=
literal|0x00800000
decl_stmt|,
DECL|enumerator|Size0
name|Size0
init|=
name|Offset1
operator|-
name|Offset0
decl_stmt|,
DECL|enumerator|Size1
name|Size1
init|=
name|Offset2
operator|-
name|Offset1
decl_stmt|,
DECL|enumerator|Size2
name|Size2
init|=
name|Offset3
operator|-
name|Offset2
decl_stmt|,
DECL|enumerator|Size3
name|Size3
init|=
name|QFreeListDefaultConstants
operator|::
name|MaxIndex
operator|-
name|Offset3
end_decl_stmt
begin_decl_stmt
DECL|enumerator|Size3
unit|};
DECL|member|Sizes
specifier|const
name|int
name|QFreeListDefaultConstants
operator|::
name|Sizes
index|[
name|QFreeListDefaultConstants
operator|::
name|BlockCount
index|]
init|=
block|{
name|Size0
block|,
name|Size1
block|,
name|Size2
block|,
name|Size3
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
