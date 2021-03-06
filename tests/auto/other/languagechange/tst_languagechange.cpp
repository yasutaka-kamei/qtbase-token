begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSet>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTranslator>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTemporaryDir>
end_include
begin_include
include|#
directive|include
file|<private/qthread_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QInputDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QColorDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDialogButtonBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QFileDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDesktopWidget>
end_include
begin_class
DECL|class|tst_languageChange
class|class
name|tst_languageChange
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_languageChange
parameter_list|()
constructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|retranslatability_data
parameter_list|()
function_decl|;
name|void
name|retranslatability
parameter_list|()
function_decl|;
private|private:
DECL|member|m_layout
name|QDialogButtonBox
operator|::
name|ButtonLayout
name|m_layout
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_languageChange
name|tst_languageChange
operator|::
name|tst_languageChange
parameter_list|()
member_init_list|:
name|m_layout
argument_list|(
name|QDialogButtonBox
operator|::
name|WinLayout
argument_list|)
block|{
if|if
condition|(
specifier|const
name|QPlatformTheme
modifier|*
name|theme
init|=
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
condition|)
name|m_layout
operator|=
cast|static_cast
argument_list|<
name|QDialogButtonBox
operator|::
name|ButtonLayout
argument_list|>
argument_list|(
name|theme
operator|->
name|themeHint
argument_list|(
name|QPlatformTheme
operator|::
name|DialogButtonBoxLayout
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|initTestCase
name|void
name|tst_languageChange
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_languageChange
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_comment
comment|/**  * Records all calls to translate()  */
end_comment
begin_class
DECL|class|TransformTranslator
class|class
name|TransformTranslator
super|:
specifier|public
name|QTranslator
block|{
name|Q_OBJECT
public|public:
DECL|function|TransformTranslator
name|TransformTranslator
parameter_list|()
member_init_list|:
name|QTranslator
argument_list|()
block|{}
DECL|function|TransformTranslator
name|TransformTranslator
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QTranslator
argument_list|(
name|parent
argument_list|)
block|{}
DECL|function|translate
name|QString
name|translate
parameter_list|(
specifier|const
name|char
modifier|*
name|context
parameter_list|,
specifier|const
name|char
modifier|*
name|sourceText
parameter_list|,
specifier|const
name|char
modifier|*
name|disambiguation
init|=
literal|0
parameter_list|,
name|int
init|=
operator|-
literal|1
parameter_list|)
specifier|const
block|{
name|QByteArray
name|total
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|total
operator|.
name|append
argument_list|(
literal|"::"
argument_list|)
expr_stmt|;
name|total
operator|.
name|append
argument_list|(
name|sourceText
argument_list|)
expr_stmt|;
if|if
condition|(
name|disambiguation
condition|)
block|{
name|total
operator|.
name|append
argument_list|(
literal|"::"
argument_list|)
expr_stmt|;
name|total
operator|.
name|append
argument_list|(
name|disambiguation
argument_list|)
expr_stmt|;
block|}
name|m_translations
operator|.
name|insert
argument_list|(
name|total
argument_list|)
expr_stmt|;
name|QString
name|res
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|int
argument_list|(
name|qstrlen
argument_list|(
name|sourceText
argument_list|)
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|QChar
name|ch
init|=
name|QLatin1Char
argument_list|(
name|sourceText
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|ch
operator|.
name|isLower
argument_list|()
condition|)
block|{
name|res
operator|.
name|append
argument_list|(
name|ch
operator|.
name|toUpper
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ch
operator|.
name|isUpper
argument_list|()
condition|)
block|{
name|res
operator|.
name|append
argument_list|(
name|ch
operator|.
name|toLower
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|res
operator|.
name|append
argument_list|(
name|ch
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|res
return|;
block|}
DECL|function|isEmpty
specifier|virtual
name|bool
name|isEmpty
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
public|public:
DECL|member|m_translations
specifier|mutable
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|m_translations
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|// Install the translator and close all application windows after a while to
end_comment
begin_comment
comment|// quit the event loop.
end_comment
begin_class
DECL|class|LanguageTestStateMachine
class|class
name|LanguageTestStateMachine
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|LanguageTestStateMachine
parameter_list|(
name|QTranslator
modifier|*
name|translator
parameter_list|)
constructor_decl|;
DECL|function|start
name|void
name|start
parameter_list|()
block|{
name|m_timer
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
private|private
name|slots
private|:
name|void
name|timeout
parameter_list|()
function_decl|;
private|private:
DECL|enum|State
DECL|enumerator|InstallTranslator
DECL|enumerator|CloseDialog
enum|enum
name|State
block|{
name|InstallTranslator
block|,
name|CloseDialog
block|}
enum|;
DECL|member|m_timer
name|QTimer
name|m_timer
decl_stmt|;
DECL|member|m_translator
name|QTranslator
modifier|*
name|m_translator
decl_stmt|;
DECL|member|m_state
name|State
name|m_state
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|LanguageTestStateMachine
name|LanguageTestStateMachine
operator|::
name|LanguageTestStateMachine
parameter_list|(
name|QTranslator
modifier|*
name|translator
parameter_list|)
member_init_list|:
name|m_translator
argument_list|(
name|translator
argument_list|)
member_init_list|,
name|m_state
argument_list|(
name|InstallTranslator
argument_list|)
block|{
name|m_timer
operator|.
name|setInterval
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|m_timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|timeout
name|void
name|LanguageTestStateMachine
operator|::
name|timeout
parameter_list|()
block|{
switch|switch
condition|(
name|m_state
condition|)
block|{
case|case
name|InstallTranslator
case|:
name|m_timer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|installTranslator
argument_list|(
name|m_translator
argument_list|)
expr_stmt|;
name|m_timer
operator|.
name|setInterval
argument_list|(
literal|2500
argument_list|)
expr_stmt|;
name|m_timer
operator|.
name|start
argument_list|()
expr_stmt|;
name|m_state
operator|=
name|CloseDialog
expr_stmt|;
break|break;
case|case
name|CloseDialog
case|:
comment|// Close repeatedly in case file dialog is slow.
name|QApplication
operator|::
name|closeAllWindows
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_enum
DECL|enum|DialogType
enum|enum
name|DialogType
block|{
DECL|enumerator|InputDialog
name|InputDialog
init|=
literal|1
block|,
DECL|enumerator|ColorDialog
name|ColorDialog
block|,
DECL|enumerator|FileDialog
name|FileDialog
block|}
enum|;
end_enum
begin_typedef
DECL|typedef|TranslationSet
typedef|typedef
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|TranslationSet
typedef|;
end_typedef
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|TranslationSet
argument_list|)
end_macro
begin_function
DECL|function|retranslatability_data
name|void
name|tst_languageChange
operator|::
name|retranslatability_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"dialogType"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|TranslationSet
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
comment|//next we fill it with data
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QInputDialog"
argument_list|)
operator|<<
name|int
argument_list|(
name|InputDialog
argument_list|)
operator|<<
operator|(
name|QSet
argument_list|<
name|QByteArray
argument_list|>
argument_list|()
operator|<<
literal|"QPlatformTheme::Cancel"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QColorDialog"
argument_list|)
operator|<<
name|int
argument_list|(
name|ColorDialog
argument_list|)
operator|<<
operator|(
name|QSet
argument_list|<
name|QByteArray
argument_list|>
argument_list|()
operator|<<
literal|"QPlatformTheme::Cancel"
operator|<<
literal|"QColorDialog::&Sat:"
operator|<<
literal|"QColorDialog::&Add to Custom Colors"
operator|<<
literal|"QColorDialog::&Green:"
operator|<<
literal|"QColorDialog::&Red:"
operator|<<
literal|"QColorDialog::Bl&ue:"
operator|<<
literal|"QColorDialog::A&lpha channel:"
operator|<<
literal|"QColorDialog::&Basic colors"
operator|<<
literal|"QColorDialog::&Custom colors"
operator|<<
literal|"QColorDialog::&Val:"
operator|<<
literal|"QColorDialog::Hu&e:"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QFileDialog"
argument_list|)
operator|<<
name|int
argument_list|(
name|FileDialog
argument_list|)
operator|<<
operator|(
name|QSet
argument_list|<
name|QByteArray
argument_list|>
argument_list|()
operator|<<
literal|"QFileDialog::All Files (*)"
operator|<<
literal|"QFileDialog::Back"
operator|<<
literal|"QFileDialog::Create New Folder"
operator|<<
literal|"QFileDialog::Detail View"
ifndef|#
directive|ifndef
name|Q_OS_MAC
operator|<<
literal|"QFileDialog::File"
endif|#
directive|endif
operator|<<
literal|"QFileDialog::Files of type:"
operator|<<
literal|"QFileDialog::Forward"
operator|<<
literal|"QFileDialog::List View"
operator|<<
literal|"QFileDialog::Look in:"
operator|<<
literal|"QFileDialog::Open"
operator|<<
literal|"QFileDialog::Parent Directory"
operator|<<
literal|"QFileDialog::Show "
operator|<<
literal|"QFileDialog::Show&hidden files"
operator|<<
literal|"QFileDialog::&Delete"
operator|<<
literal|"QFileDialog::&New Folder"
operator|<<
literal|"QFileDialog::&Rename"
operator|<<
literal|"QFileSystemModel::Date Modified"
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"QFileSystemModel::My Computer"
else|#
directive|else
operator|<<
literal|"QFileSystemModel::Computer"
endif|#
directive|endif
operator|<<
literal|"QFileSystemModel::Size"
ifdef|#
directive|ifdef
name|Q_OS_MAC
operator|<<
literal|"QFileSystemModel::Kind::Match OS X Finder"
else|#
directive|else
operator|<<
literal|"QFileSystemModel::Type::All other platforms"
endif|#
directive|endif
comment|//<< "QFileSystemModel::%1 KB"
operator|<<
literal|"QPlatformTheme::Cancel"
operator|<<
literal|"QPlatformTheme::Open"
operator|<<
literal|"QFileDialog::File&name:"
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|retranslatability
name|void
name|tst_languageChange
operator|::
name|retranslatability
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|dialogType
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|TranslationSet
argument_list|,
name|expected
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_layout
operator|==
name|QDialogButtonBox
operator|::
name|GnomeLayout
condition|)
name|QSKIP
argument_list|(
literal|"The input data are not suitable for this layout (QDialogButtonBox::GnomeLayout)"
argument_list|)
expr_stmt|;
comment|// This will always be queried for when a language changes
name|expected
operator|.
name|insert
argument_list|(
literal|"QGuiApplication::QT_LAYOUT_DIRECTION::Translate this string to the string 'LTR' in left-to-right "
literal|"languages or to 'RTL' in right-to-left languages (such as Hebrew and Arabic) to "
literal|"get proper widget layout."
argument_list|)
expr_stmt|;
name|TransformTranslator
name|translator
decl_stmt|;
name|LanguageTestStateMachine
name|stateMachine
argument_list|(
operator|&
name|translator
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|dialogType
condition|)
block|{
case|case
name|InputDialog
case|:
name|stateMachine
operator|.
name|start
argument_list|()
expr_stmt|;
name|QInputDialog
operator|::
name|getInt
argument_list|(
literal|0
argument_list|,
name|QLatin1String
argument_list|(
literal|"title"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"label"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|ColorDialog
case|:
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|QSKIP
argument_list|(
literal|"The native color dialog is used on Mac OS"
argument_list|)
expr_stmt|;
else|#
directive|else
name|stateMachine
operator|.
name|start
argument_list|()
expr_stmt|;
name|QColorDialog
operator|::
name|getColor
argument_list|()
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|FileDialog
case|:
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|QSKIP
argument_list|(
literal|"The native file dialog is used on Mac OS"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QFileDialog
name|dlg
decl_stmt|;
name|dlg
operator|.
name|setOption
argument_list|(
name|QFileDialog
operator|::
name|DontUseNativeDialog
argument_list|)
expr_stmt|;
name|QString
name|tempDirPattern
init|=
name|QDir
operator|::
name|tempPath
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|tempDirPattern
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|tempDirPattern
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
name|tempDirPattern
operator|+=
name|QStringLiteral
argument_list|(
literal|"languagechangetestdirXXXXXX"
argument_list|)
expr_stmt|;
name|QTemporaryDir
name|temporaryDir
argument_list|(
name|tempDirPattern
argument_list|)
decl_stmt|;
name|temporaryDir
operator|.
name|setAutoRemove
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|temporaryDir
operator|.
name|isValid
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|temporaryDir
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|finalDir
init|=
name|temporaryDir
operator|.
name|path
argument_list|()
operator|+
name|QStringLiteral
argument_list|(
literal|"/finaldir"
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|fooName
init|=
name|temporaryDir
operator|.
name|path
argument_list|()
operator|+
name|QStringLiteral
argument_list|(
literal|"/foo"
argument_list|)
decl_stmt|;
name|QDir
name|dir
decl_stmt|;
name|QVERIFY
argument_list|(
name|dir
operator|.
name|mkpath
argument_list|(
name|finalDir
argument_list|)
argument_list|)
expr_stmt|;
name|QFile
name|fooFile
argument_list|(
name|fooName
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|fooFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
argument_list|)
expr_stmt|;
name|fooFile
operator|.
name|write
argument_list|(
literal|"test"
argument_list|)
expr_stmt|;
name|fooFile
operator|.
name|close
argument_list|()
expr_stmt|;
name|dlg
operator|.
name|setDirectory
argument_list|(
name|temporaryDir
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|dlg
operator|.
name|setDirectory
argument_list|(
literal|"\\Windows"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|dlg
operator|.
name|setFileMode
argument_list|(
name|QFileDialog
operator|::
name|ExistingFiles
argument_list|)
expr_stmt|;
name|dlg
operator|.
name|setViewMode
argument_list|(
name|QFileDialog
operator|::
name|Detail
argument_list|)
expr_stmt|;
name|stateMachine
operator|.
name|start
argument_list|()
expr_stmt|;
name|dlg
operator|.
name|exec
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|3000
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|// In case we use a Color dialog, we do not want to test for
comment|// strings non existing in the dialog and which do not get
comment|// translated.
if|if
condition|(
operator|(
name|dialogType
operator|==
name|ColorDialog
operator|)
operator|&&
ifndef|#
directive|ifndef
name|Q_OS_WINCE
operator|(
name|qApp
operator|->
name|desktop
argument_list|()
operator|->
name|width
argument_list|()
operator|<
literal|480
operator|||
name|qApp
operator|->
name|desktop
argument_list|()
operator|->
name|height
argument_list|()
operator|<
literal|350
operator|)
else|#
directive|else
literal|true
comment|// On Qt/WinCE we always use compact mode
endif|#
directive|endif
condition|)
block|{
name|expected
operator|.
name|remove
argument_list|(
literal|"QColorDialog::&Basic colors"
argument_list|)
expr_stmt|;
name|expected
operator|.
name|remove
argument_list|(
literal|"QColorDialog::&Custom colors"
argument_list|)
expr_stmt|;
name|expected
operator|.
name|remove
argument_list|(
literal|"QColorDialog::&Define Custom Colors>>"
argument_list|)
expr_stmt|;
name|expected
operator|.
name|remove
argument_list|(
literal|"QColorDialog::&Add to Custom Colors"
argument_list|)
expr_stmt|;
block|}
comment|// see if all of our *expected* translations was translated.
comment|// (There might be more, but thats not that bad)
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|commonTranslations
init|=
name|expected
decl_stmt|;
name|commonTranslations
operator|.
name|intersect
argument_list|(
name|translator
operator|.
name|m_translations
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|expected
operator|.
name|subtract
argument_list|(
name|commonTranslations
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Missing:"
operator|<<
name|expected
expr_stmt|;
if|if
condition|(
operator|!
name|translator
operator|.
name|m_translations
operator|.
name|subtract
argument_list|(
name|commonTranslations
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Unexpected:"
operator|<<
name|translator
operator|.
name|m_translations
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|expected
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_languageChange
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_languagechange.moc"
end_include
end_unit
