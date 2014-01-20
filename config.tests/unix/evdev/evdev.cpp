begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<linux/input.h>
end_include
begin_include
include|#
directive|include
file|<linux/kd.h>
end_include
begin_enum
enum|enum
block|{
DECL|enumerator|e1
name|e1
init|=
name|ABS_PRESSURE
block|,
DECL|enumerator|e2
name|e2
init|=
name|ABS_X
block|,
DECL|enumerator|e3
name|e3
init|=
name|REL_X
block|,
DECL|enumerator|e4
name|e4
init|=
name|SYN_REPORT
block|, }
enum|;
end_enum
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
operator|::
name|input_event
name|buf
index|[
literal|32
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|buf
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
