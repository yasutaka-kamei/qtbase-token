begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<unicode/utypes.h>
end_include
begin_include
include|#
directive|include
file|<unicode/ucol.h>
end_include
begin_include
include|#
directive|include
file|<unicode/ustring.h>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
block|{
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|UCollator
modifier|*
name|collator
init|=
name|ucol_open
argument_list|(
literal|"ru_RU"
argument_list|,
operator|&
name|status
argument_list|)
decl_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|status
argument_list|)
condition|)
return|return
literal|0
return|;
name|ucol_close
argument_list|(
name|collator
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
