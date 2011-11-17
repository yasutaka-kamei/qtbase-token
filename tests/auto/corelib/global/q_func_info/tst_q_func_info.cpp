begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_class
DECL|class|tst_q_func_info
class|class
name|tst_q_func_info
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|callFunctions
parameter_list|()
specifier|const
function_decl|;
name|void
name|isOfTypeConstChar
parameter_list|()
specifier|const
function_decl|;
name|void
name|availableWithoutDebug
parameter_list|()
specifier|const
function_decl|;
private|private:
specifier|static
name|void
name|staticMember
parameter_list|()
function_decl|;
name|void
name|regularMember
parameter_list|()
specifier|const
function_decl|;
name|void
name|memberWithArguments
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|,
name|int
name|value
parameter_list|,
specifier|const
name|int
name|value2
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|staticRegularFunction
specifier|static
name|void
name|staticRegularFunction
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
block|}
end_function
begin_function
DECL|function|regularFunction
name|void
name|regularFunction
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|templateFunction
name|void
name|templateFunction
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|,
specifier|const
name|int
name|value
parameter_list|>
DECL|function|valueTemplateFunction
name|void
name|valueTemplateFunction
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
block|}
end_function
begin_function
DECL|function|staticMember
name|void
name|tst_q_func_info
operator|::
name|staticMember
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
block|}
end_function
begin_function
DECL|function|regularMember
name|void
name|tst_q_func_info
operator|::
name|regularMember
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
block|}
end_function
begin_function
DECL|function|memberWithArguments
name|void
name|tst_q_func_info
operator|::
name|memberWithArguments
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
name|int
parameter_list|,
specifier|const
name|int
parameter_list|)
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal     We don't do much here. We call different kinds of     functions to make sure we don't crash anything or that valgrind     is unhappy.  */
end_comment
begin_function
DECL|function|callFunctions
name|void
name|tst_q_func_info
operator|::
name|callFunctions
parameter_list|()
specifier|const
block|{
name|staticRegularFunction
argument_list|()
expr_stmt|;
name|regularFunction
argument_list|()
expr_stmt|;
name|templateFunction
argument_list|<
name|char
argument_list|>
argument_list|()
expr_stmt|;
name|valueTemplateFunction
argument_list|<
name|int
argument_list|,
literal|3
argument_list|>
argument_list|()
expr_stmt|;
name|staticMember
argument_list|()
expr_stmt|;
name|regularMember
argument_list|()
expr_stmt|;
name|memberWithArguments
argument_list|(
name|QString
argument_list|()
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isOfTypeConstChar
name|void
name|tst_q_func_info
operator|::
name|isOfTypeConstChar
parameter_list|()
specifier|const
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|QString
operator|::
name|fromLatin1
argument_list|(
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/* \internal     Ensure that the macro is available even though QT_NO_DEBUG     is defined.  If QT_NO_DEBUG is not defined, we define it     just for this function then undef it again afterwards.  */
end_comment
begin_function
DECL|function|availableWithoutDebug
name|void
name|tst_q_func_info
operator|::
name|availableWithoutDebug
parameter_list|()
specifier|const
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
DECL|macro|UNDEF_NO_DEBUG
define|#
directive|define
name|UNDEF_NO_DEBUG
DECL|macro|QT_NO_DEBUG
define|#
directive|define
name|QT_NO_DEBUG
endif|#
directive|endif
name|QVERIFY
argument_list|(
operator|!
name|QString
operator|::
name|fromLatin1
argument_list|(
name|Q_FUNC_INFO
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|UNDEF_NO_DEBUG
DECL|macro|QT_NO_DEBUG
undef|#
directive|undef
name|QT_NO_DEBUG
DECL|macro|UNDEF_NO_DEBUG
undef|#
directive|undef
name|UNDEF_NO_DEBUG
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_q_func_info
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_q_func_info.moc"
end_include
end_unit
