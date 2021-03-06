begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qmimetype_p.h>
end_include
begin_include
include|#
directive|include
file|<qmimetype.h>
end_include
begin_include
include|#
directive|include
file|<qmimedatabase.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_qmimetype
class|class
name|tst_qmimetype
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|isValid
parameter_list|()
function_decl|;
name|void
name|name
parameter_list|()
function_decl|;
name|void
name|genericIconName
parameter_list|()
function_decl|;
name|void
name|iconName
parameter_list|()
function_decl|;
name|void
name|suffixes
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// ------------------------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|initTestCase
name|void
name|tst_qmimetype
operator|::
name|initTestCase
parameter_list|()
block|{
name|qputenv
argument_list|(
literal|"XDG_DATA_DIRS"
argument_list|,
literal|"doesnotexist"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// ------------------------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|qMimeTypeName
specifier|static
name|QString
name|qMimeTypeName
parameter_list|()
block|{
specifier|static
specifier|const
name|QString
name|result
argument_list|(
literal|"No name of the MIME type"
argument_list|)
decl_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|qMimeTypeGenericIconName
specifier|static
name|QString
name|qMimeTypeGenericIconName
parameter_list|()
block|{
specifier|static
specifier|const
name|QString
name|result
argument_list|(
literal|"No file name of an icon image that represents the MIME type"
argument_list|)
decl_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|qMimeTypeIconName
specifier|static
name|QString
name|qMimeTypeIconName
parameter_list|()
block|{
specifier|static
specifier|const
name|QString
name|result
argument_list|(
literal|"No file name of an icon image that represents the MIME type"
argument_list|)
decl_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|buildQMimeTypeFilenameExtensions
specifier|static
name|QStringList
name|buildQMimeTypeFilenameExtensions
parameter_list|()
block|{
name|QStringList
name|result
decl_stmt|;
name|result
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"*.png"
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|qMimeTypeGlobPatterns
specifier|static
name|QStringList
name|qMimeTypeGlobPatterns
parameter_list|()
block|{
specifier|static
specifier|const
name|QStringList
name|result
argument_list|(
name|buildQMimeTypeFilenameExtensions
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|// ------------------------------------------------------------------------------------------------
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_COMPILER_RVALUE_REFS
end_ifndef
begin_function
name|QMIMETYPE_BUILDER
else|#
directive|else
name|QMIMETYPE_BUILDER_FROM_RVALUE_REFS
endif|#
directive|endif
comment|// ------------------------------------------------------------------------------------------------
DECL|function|isValid
name|void
name|tst_qmimetype
operator|::
name|isValid
parameter_list|()
block|{
name|QMimeType
name|instantiatedQMimeType
argument_list|(
name|buildQMimeType
argument_list|(
name|qMimeTypeName
argument_list|()
argument_list|,
name|qMimeTypeGenericIconName
argument_list|()
argument_list|,
name|qMimeTypeIconName
argument_list|()
argument_list|,
name|qMimeTypeGlobPatterns
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|instantiatedQMimeType
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QMimeType
name|otherQMimeType
argument_list|(
name|instantiatedQMimeType
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|otherQMimeType
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|instantiatedQMimeType
argument_list|,
name|otherQMimeType
argument_list|)
expr_stmt|;
name|QMimeType
name|defaultQMimeType
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|defaultQMimeType
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// ------------------------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|name
name|void
name|tst_qmimetype
operator|::
name|name
parameter_list|()
block|{
name|QMimeType
name|instantiatedQMimeType
argument_list|(
name|buildQMimeType
argument_list|(
name|qMimeTypeName
argument_list|()
argument_list|,
name|qMimeTypeGenericIconName
argument_list|()
argument_list|,
name|qMimeTypeIconName
argument_list|()
argument_list|,
name|qMimeTypeGlobPatterns
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QMimeType
name|otherQMimeType
argument_list|(
name|buildQMimeType
argument_list|(
name|QString
argument_list|()
argument_list|,
name|qMimeTypeGenericIconName
argument_list|()
argument_list|,
name|qMimeTypeIconName
argument_list|()
argument_list|,
name|qMimeTypeGlobPatterns
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
comment|// Verify that the Name is part of the equality test:
name|QCOMPARE
argument_list|(
name|instantiatedQMimeType
operator|.
name|name
argument_list|()
argument_list|,
name|qMimeTypeName
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|instantiatedQMimeType
operator|!=
name|otherQMimeType
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|instantiatedQMimeType
operator|==
name|otherQMimeType
operator|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// ------------------------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|genericIconName
name|void
name|tst_qmimetype
operator|::
name|genericIconName
parameter_list|()
block|{
name|QMimeType
name|instantiatedQMimeType
argument_list|(
name|buildQMimeType
argument_list|(
name|qMimeTypeName
argument_list|()
argument_list|,
name|qMimeTypeGenericIconName
argument_list|()
argument_list|,
name|qMimeTypeIconName
argument_list|()
argument_list|,
name|qMimeTypeGlobPatterns
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|instantiatedQMimeType
operator|.
name|genericIconName
argument_list|()
argument_list|,
name|qMimeTypeGenericIconName
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// ------------------------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|iconName
name|void
name|tst_qmimetype
operator|::
name|iconName
parameter_list|()
block|{
name|QMimeType
name|instantiatedQMimeType
argument_list|(
name|buildQMimeType
argument_list|(
name|qMimeTypeName
argument_list|()
argument_list|,
name|qMimeTypeGenericIconName
argument_list|()
argument_list|,
name|qMimeTypeIconName
argument_list|()
argument_list|,
name|qMimeTypeGlobPatterns
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|instantiatedQMimeType
operator|.
name|iconName
argument_list|()
argument_list|,
name|qMimeTypeIconName
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// ------------------------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|suffixes
name|void
name|tst_qmimetype
operator|::
name|suffixes
parameter_list|()
block|{
name|QMimeType
name|instantiatedQMimeType
argument_list|(
name|buildQMimeType
argument_list|(
name|qMimeTypeName
argument_list|()
argument_list|,
name|qMimeTypeGenericIconName
argument_list|()
argument_list|,
name|qMimeTypeIconName
argument_list|()
argument_list|,
name|qMimeTypeGlobPatterns
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|instantiatedQMimeType
operator|.
name|globPatterns
argument_list|()
argument_list|,
name|qMimeTypeGlobPatterns
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|instantiatedQMimeType
operator|.
name|suffixes
argument_list|()
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"png"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// ------------------------------------------------------------------------------------------------
end_comment
begin_macro
name|QTEST_GUILESS_MAIN
argument_list|(
argument|tst_qmimetype
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmimetype.moc"
end_include
end_unit
