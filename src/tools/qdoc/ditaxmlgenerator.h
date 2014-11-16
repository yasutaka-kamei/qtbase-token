begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DITAXMLGENERATOR_H
end_ifndef
begin_define
DECL|macro|DITAXMLGENERATOR_H
define|#
directive|define
name|DITAXMLGENERATOR_H
end_define
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qxmlstream.h>
end_include
begin_include
include|#
directive|include
file|"codemarker.h"
end_include
begin_include
include|#
directive|include
file|"generator.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|QString
DECL|typedef|GuidMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|GuidMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|GuidMaps
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|GuidMap
operator|*
operator|>
name|GuidMaps
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|DitaXmlGenerator
range|:
name|public
name|Generator
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::DitaXmlGenerator
argument_list|)
name|public
operator|:
expr|enum
name|SinceType
block|{
name|Namespace
block|,
name|Class
block|,
name|MemberFunction
block|,
name|NamespaceFunction
block|,
name|GlobalFunction
block|,
name|Macro
block|,
name|Enum
block|,
name|Typedef
block|,
name|Property
block|,
name|Variable
block|,
name|QmlClass
block|,
name|QmlProperty
block|,
name|QmlSignal
block|,
name|QmlSignalHandler
block|,
name|QmlMethod
block|,
name|LastSinceType
block|}
block|;      enum
name|DitaTag
block|{
name|DT_NONE
block|,
name|DT_alt
block|,
name|DT_apiData
block|,
name|DT_apiDef
block|,
name|DT_apiDefItem
block|,
name|DT_apiDesc
block|,
name|DT_apiDetail
block|,
name|DT_apiItemName
block|,
name|DT_APIMap
block|,
name|DT_apiName
block|,
name|DT_apiRef
block|,
name|DT_apiRelation
block|,
name|DT_audience
block|,
name|DT_author
block|,
name|DT_b
block|,
name|DT_body
block|,
name|DT_bodydiv
block|,
name|DT_brand
block|,
name|DT_category
block|,
name|DT_codeblock
block|,
name|DT_colspec
block|,
name|DT_comment
block|,
name|DT_component
block|,
name|DT_copyrholder
block|,
name|DT_copyright
block|,
name|DT_copyryear
block|,
name|DT_created
block|,
name|DT_critdates
block|,
name|DT_cxxAPIMap
block|,
name|DT_cxxClass
block|,
name|DT_cxxClassAbstract
block|,
name|DT_cxxClassAccessSpecifier
block|,
name|DT_cxxClassAPIItemLocation
block|,
name|DT_cxxClassBaseClass
block|,
name|DT_cxxClassDeclarationFile
block|,
name|DT_cxxClassDeclarationFileLine
block|,
name|DT_cxxClassDeclarationFileLineStart
block|,
name|DT_cxxClassDeclarationFileLineEnd
block|,
name|DT_cxxClassDefinition
block|,
name|DT_cxxClassDerivation
block|,
name|DT_cxxClassDerivationAccessSpecifier
block|,
name|DT_cxxClassDerivations
block|,
name|DT_cxxClassDetail
block|,
name|DT_cxxClassNested
block|,
name|DT_cxxClassNestedClass
block|,
name|DT_cxxClassNestedDetail
block|,
name|DT_cxxDefine
block|,
name|DT_cxxDefineAccessSpecifier
block|,
name|DT_cxxDefineAPIItemLocation
block|,
name|DT_cxxDefineDeclarationFile
block|,
name|DT_cxxDefineDeclarationFileLine
block|,
name|DT_cxxDefineDefinition
block|,
name|DT_cxxDefineDetail
block|,
name|DT_cxxDefineNameLookup
block|,
name|DT_cxxDefineParameter
block|,
name|DT_cxxDefineParameterDeclarationName
block|,
name|DT_cxxDefineParameters
block|,
name|DT_cxxDefinePrototype
block|,
name|DT_cxxDefineReimplemented
block|,
name|DT_cxxEnumeration
block|,
name|DT_cxxEnumerationAccessSpecifier
block|,
name|DT_cxxEnumerationAPIItemLocation
block|,
name|DT_cxxEnumerationDeclarationFile
block|,
name|DT_cxxEnumerationDeclarationFileLine
block|,
name|DT_cxxEnumerationDeclarationFileLineStart
block|,
name|DT_cxxEnumerationDeclarationFileLineEnd
block|,
name|DT_cxxEnumerationDefinition
block|,
name|DT_cxxEnumerationDetail
block|,
name|DT_cxxEnumerationNameLookup
block|,
name|DT_cxxEnumerationPrototype
block|,
name|DT_cxxEnumerationScopedName
block|,
name|DT_cxxEnumerator
block|,
name|DT_cxxEnumeratorInitialiser
block|,
name|DT_cxxEnumeratorNameLookup
block|,
name|DT_cxxEnumeratorPrototype
block|,
name|DT_cxxEnumerators
block|,
name|DT_cxxEnumeratorScopedName
block|,
name|DT_cxxFunction
block|,
name|DT_cxxFunctionAccessSpecifier
block|,
name|DT_cxxFunctionAPIItemLocation
block|,
name|DT_cxxFunctionConst
block|,
name|DT_cxxFunctionConstructor
block|,
name|DT_cxxFunctionDeclarationFile
block|,
name|DT_cxxFunctionDeclarationFileLine
block|,
name|DT_cxxFunctionDeclaredType
block|,
name|DT_cxxFunctionDefinition
block|,
name|DT_cxxFunctionDestructor
block|,
name|DT_cxxFunctionDetail
block|,
name|DT_cxxFunctionNameLookup
block|,
name|DT_cxxFunctionParameter
block|,
name|DT_cxxFunctionParameterDeclarationName
block|,
name|DT_cxxFunctionParameterDeclaredType
block|,
name|DT_cxxFunctionParameterDefaultValue
block|,
name|DT_cxxFunctionParameters
block|,
name|DT_cxxFunctionPrototype
block|,
name|DT_cxxFunctionPureVirtual
block|,
name|DT_cxxFunctionReimplemented
block|,
name|DT_cxxFunctionScopedName
block|,
name|DT_cxxFunctionStorageClassSpecifierStatic
block|,
name|DT_cxxFunctionVirtual
block|,
name|DT_cxxTypedef
block|,
name|DT_cxxTypedefAccessSpecifier
block|,
name|DT_cxxTypedefAPIItemLocation
block|,
name|DT_cxxTypedefDeclarationFile
block|,
name|DT_cxxTypedefDeclarationFileLine
block|,
name|DT_cxxTypedefDefinition
block|,
name|DT_cxxTypedefDetail
block|,
name|DT_cxxTypedefNameLookup
block|,
name|DT_cxxTypedefScopedName
block|,
name|DT_cxxVariable
block|,
name|DT_cxxVariableAccessSpecifier
block|,
name|DT_cxxVariableAPIItemLocation
block|,
name|DT_cxxVariableDeclarationFile
block|,
name|DT_cxxVariableDeclarationFileLine
block|,
name|DT_cxxVariableDeclaredType
block|,
name|DT_cxxVariableDefinition
block|,
name|DT_cxxVariableDetail
block|,
name|DT_cxxVariableNameLookup
block|,
name|DT_cxxVariablePrototype
block|,
name|DT_cxxVariableReimplemented
block|,
name|DT_cxxVariableScopedName
block|,
name|DT_cxxVariableStorageClassSpecifierStatic
block|,
name|DT_data
block|,
name|DT_dataabout
block|,
name|DT_dd
block|,
name|DT_dl
block|,
name|DT_dlentry
block|,
name|DT_dt
block|,
name|DT_entry
block|,
name|DT_fig
block|,
name|DT_i
block|,
name|DT_image
block|,
name|DT_keyword
block|,
name|DT_keywords
block|,
name|DT_li
block|,
name|DT_link
block|,
name|DT_linktext
block|,
name|DT_lq
block|,
name|DT_map
block|,
name|DT_mapref
block|,
name|DT_metadata
block|,
name|DT_note
block|,
name|DT_ol
block|,
name|DT_othermeta
block|,
name|DT_p
block|,
name|DT_parameter
block|,
name|DT_permissions
block|,
name|DT_ph
block|,
name|DT_platform
block|,
name|DT_pre
block|,
name|DT_prodinfo
block|,
name|DT_prodname
block|,
name|DT_prolog
block|,
name|DT_publisher
block|,
name|DT_qmlAttached
block|,
name|DT_qmlDetail
block|,
name|DT_qmlImportModule
block|,
name|DT_qmlInheritedBy
block|,
name|DT_qmlInherits
block|,
name|DT_qmlInstantiates
block|,
name|DT_qmlMethod
block|,
name|DT_qmlMethodDef
block|,
name|DT_qmlMethodDetail
block|,
name|DT_qmlName
block|,
name|DT_qmlProperty
block|,
name|DT_qmlPropertyDef
block|,
name|DT_qmlPropertyDetail
block|,
name|DT_qmlPropertyGroup
block|,
name|DT_qmlPropertyGroupDef
block|,
name|DT_qmlPropertyGroupDetail
block|,
name|DT_qmlQualifier
block|,
name|DT_qmlSignal
block|,
name|DT_qmlSignalDef
block|,
name|DT_qmlSignalDetail
block|,
name|DT_qmlSignalHandler
block|,
name|DT_qmlSignalHandlerDEf
block|,
name|DT_qmlSignalHandlerDetail
block|,
name|DT_qmlSignature
block|,
name|DT_qmlSince
block|,
name|DT_qmlType
block|,
name|DT_qmlTypeDef
block|,
name|DT_qmlTypeDetail
block|,
name|DT_relatedLinks
block|,
name|DT_resourceid
block|,
name|DT_revised
block|,
name|DT_row
block|,
name|DT_section
block|,
name|DT_sectiondiv
block|,
name|DT_shortdesc
block|,
name|DT_simpletable
block|,
name|DT_source
block|,
name|DT_stentry
block|,
name|DT_sthead
block|,
name|DT_strow
block|,
name|DT_sub
block|,
name|DT_sup
block|,
name|DT_table
block|,
name|DT_tbody
block|,
name|DT_tgroup
block|,
name|DT_thead
block|,
name|DT_title
block|,
name|DT_tm
block|,
name|DT_topic
block|,
name|DT_topicmeta
block|,
name|DT_topicref
block|,
name|DT_tt
block|,
name|DT_u
block|,
name|DT_uicontrol
block|,
name|DT_ul
block|,
name|DT_unknown
block|,
name|DT_vrm
block|,
name|DT_vrmlist
block|,
name|DT_xref
block|,
name|DT_LAST
block|}
block|;
name|public
operator|:
name|DitaXmlGenerator
argument_list|()
block|;
operator|~
name|DitaXmlGenerator
argument_list|()
block|;
name|virtual
name|void
name|initializeGenerator
argument_list|(
argument|const Config& config
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|terminateGenerator
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|format
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|canHandleFormat
argument_list|(
argument|const QString& format
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|generateDocs
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QString
name|protectEnc
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
block|;
specifier|static
name|QString
name|protect
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|,
specifier|const
name|QString
operator|&
name|encoding
operator|=
literal|"ISO-8859-1"
argument_list|)
block|;
specifier|static
name|QString
name|cleanRef
argument_list|(
specifier|const
name|QString
operator|&
name|ref
argument_list|)
block|;
specifier|static
name|QString
name|sinceTitle
argument_list|(
argument|int i
argument_list|)
block|{
return|return
name|sinceTitles
index|[
name|i
index|]
return|;
block|}
name|protected
operator|:
name|virtual
name|int
name|generateAtom
argument_list|(
argument|const Atom* atom
argument_list|,
argument|const Node* relative
argument_list|,
argument|CodeMarker* marker
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|generateClassLikeNode
argument_list|(
argument|InnerNode* inner
argument_list|,
argument|CodeMarker* marker
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|generateQmlBasicTypePage
argument_list|(
argument|QmlBasicTypeNode* qbtn
argument_list|,
argument|CodeMarker* marker
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|generateDocNode
argument_list|(
argument|DocNode* dn
argument_list|,
argument|CodeMarker* marker
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|generateCollectionNode
argument_list|(
argument|CollectionNode* cn
argument_list|,
argument|CodeMarker* marker
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|fileExtension
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|guidForNode
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
name|virtual
name|QString
name|linkForNode
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|)
block|;
name|void
name|writeXrefListItem
argument_list|(
specifier|const
name|QString
operator|&
name|link
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QString
name|fullQualification
argument_list|(
specifier|const
name|Node
operator|*
name|n
argument_list|)
block|;
name|void
name|writeCharacters
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|writeDerivations
argument_list|(
specifier|const
name|ClassNode
operator|*
name|cn
argument_list|)
block|;
name|void
name|writeLocation
argument_list|(
specifier|const
name|Node
operator|*
name|n
argument_list|)
block|;
name|void
name|writeFunctions
argument_list|(
specifier|const
name|Section
operator|&
name|s
argument_list|,
specifier|const
name|InnerNode
operator|*
name|parent
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|QString
operator|&
name|attribute
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|writeNestedClasses
argument_list|(
specifier|const
name|Section
operator|&
name|s
argument_list|,
specifier|const
name|Node
operator|*
name|n
argument_list|)
block|;
name|void
name|replaceTypesWithLinks
argument_list|(
specifier|const
name|Node
operator|*
name|n
argument_list|,
specifier|const
name|InnerNode
operator|*
name|parent
argument_list|,
name|QString
operator|&
name|src
argument_list|)
block|;
name|void
name|writeParameters
argument_list|(
specifier|const
name|FunctionNode
operator|*
name|fn
argument_list|,
specifier|const
name|InnerNode
operator|*
name|parent
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|writeEnumerations
argument_list|(
specifier|const
name|Section
operator|&
name|s
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|QString
operator|&
name|attribute
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|writeTypedefs
argument_list|(
specifier|const
name|Section
operator|&
name|s
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|QString
operator|&
name|attribute
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|writeDataMembers
argument_list|(
specifier|const
name|Section
operator|&
name|s
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|QString
operator|&
name|attribute
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|writeProperties
argument_list|(
specifier|const
name|Section
operator|&
name|s
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|QString
operator|&
name|attribute
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|writeMacros
argument_list|(
specifier|const
name|Section
operator|&
name|s
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|QString
operator|&
name|attribute
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|writePropertyParameter
argument_list|(
specifier|const
name|QString
operator|&
name|tag
argument_list|,
specifier|const
name|NodeList
operator|&
name|nlist
argument_list|)
block|;
name|void
name|writeRelatedLinks
argument_list|(
specifier|const
name|Node
operator|*
name|dn
argument_list|)
block|;
name|void
name|writeLink
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
specifier|const
name|QString
operator|&
name|tex
argument_list|,
specifier|const
name|QString
operator|&
name|role
argument_list|)
block|;
name|void
name|writeProlog
argument_list|(
specifier|const
name|InnerNode
operator|*
name|inner
argument_list|)
block|;
name|bool
name|writeMetadataElement
argument_list|(
argument|const InnerNode* inner
argument_list|,
argument|DitaXmlGenerator::DitaTag t
argument_list|,
argument|bool force=true
argument_list|)
block|;
name|bool
name|writeMetadataElements
argument_list|(
argument|const InnerNode* inner
argument_list|,
argument|DitaXmlGenerator::DitaTag t
argument_list|)
block|;
name|void
name|writeHrefAttribute
argument_list|(
specifier|const
name|QString
operator|&
name|href
argument_list|)
block|;
name|QString
name|getMetadataElement
argument_list|(
argument|const InnerNode* inner
argument_list|,
argument|DitaXmlGenerator::DitaTag t
argument_list|)
block|;
name|QStringList
name|getMetadataElements
argument_list|(
argument|const InnerNode* inner
argument_list|,
argument|DitaXmlGenerator::DitaTag t
argument_list|)
block|;
name|private
operator|:
expr|enum
name|SubTitleSize
block|{
name|SmallSubTitle
block|,
name|LargeSubTitle
block|}
block|;
specifier|const
name|QPair
operator|<
name|QString
block|,
name|QString
operator|>
name|anchorForNode
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
name|void
name|generateHeader
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|void
name|generateBrief
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateTableOfContents
argument_list|(
argument|const Node* node
argument_list|,
argument|CodeMarker* marker
argument_list|,
argument|Doc::Sections sectioningUnit
argument_list|,
argument|int numColumns
argument_list|,
argument|const Node* relative =
literal|0
argument_list|)
block|;
name|void
name|generateLowStatusMembers
argument_list|(
argument|InnerNode* inner
argument_list|,
argument|CodeMarker* marker
argument_list|,
argument|CodeMarker::Status status
argument_list|)
block|;
name|void
name|generateClassHierarchy
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|NodeMap
operator|&
name|classMap
argument_list|)
block|;
name|void
name|generateAnnotatedList
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|NodeMap
operator|&
name|nodeMap
argument_list|)
block|;
name|void
name|generateAnnotatedList
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|NodeList
operator|&
name|nodes
argument_list|)
block|;
name|void
name|generateCompactList
argument_list|(
argument|ListType listType
argument_list|,
argument|const Node* relative
argument_list|,
argument|const NodeMap& classMap
argument_list|,
argument|bool includeAlphabet
argument_list|,
argument|QString commonPrefix
argument_list|)
block|;
name|void
name|generateFunctionIndex
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|)
block|;
name|void
name|generateLegaleseList
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateOverviewList
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|)
block|;
name|void
name|generateQmlSummary
argument_list|(
specifier|const
name|Section
operator|&
name|section
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateQmlItem
argument_list|(
argument|const Node* node
argument_list|,
argument|const Node* relative
argument_list|,
argument|CodeMarker* marker
argument_list|,
argument|bool summary
argument_list|)
block|;
name|void
name|startQmlProperty
argument_list|(
name|QmlPropertyNode
operator|*
name|qpn
argument_list|,
specifier|const
name|InnerNode
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|writeQmlRef
argument_list|(
argument|DitaTag tag
argument_list|,
argument|Node* node
argument_list|,
argument|const InnerNode* relative
argument_list|,
argument|CodeMarker* marker
argument_list|)
block|;
name|void
name|generateDetailedQmlMember
argument_list|(
name|Node
operator|*
name|node
argument_list|,
specifier|const
name|InnerNode
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateQmlInherits
argument_list|(
argument|QmlClassNode* qcn
argument_list|,
argument|CodeMarker* marker
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|generateQmlInheritedBy
argument_list|(
argument|const QmlClassNode* qcn
argument_list|,
argument|CodeMarker* marker
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|generateQmlInstantiates
argument_list|(
name|QmlClassNode
operator|*
name|qcn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateInstantiatedBy
argument_list|(
name|ClassNode
operator|*
name|cn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateQmlModuleDef
argument_list|(
name|QmlClassNode
operator|*
name|qcn
argument_list|)
block|;
name|void
name|generateQmlSince
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
name|void
name|generateSection
argument_list|(
argument|const NodeList& nl
argument_list|,
argument|const Node* relative
argument_list|,
argument|CodeMarker* marker
argument_list|,
argument|CodeMarker::SynopsisStyle style
argument_list|)
block|;
name|QString
name|getMarkedUpSynopsis
argument_list|(
argument|const Node* node
argument_list|,
argument|const Node* relative
argument_list|,
argument|CodeMarker* marker
argument_list|,
argument|CodeMarker::SynopsisStyle style
argument_list|)
block|;
name|void
name|generateSectionInheritedList
argument_list|(
specifier|const
name|Section
operator|&
name|section
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|)
block|;
name|void
name|writeText
argument_list|(
specifier|const
name|QString
operator|&
name|markedCode
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|)
block|;
name|void
name|generateFullName
argument_list|(
specifier|const
name|Node
operator|*
name|apparentNode
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
specifier|const
name|Node
operator|*
name|actualNode
operator|=
literal|0
argument_list|)
block|;
name|void
name|generateLink
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateStatus
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|QString
name|getLink
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
specifier|const
name|Node
operator|*
operator|*
name|node
argument_list|)
block|;
name|QString
name|getAutoLink
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
specifier|const
name|Node
operator|*
operator|*
name|node
argument_list|)
block|;
name|QString
name|registerRef
argument_list|(
specifier|const
name|QString
operator|&
name|ref
argument_list|)
block|;
name|virtual
name|QString
name|fileBase
argument_list|(
argument|const Node *node
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|fileName
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
specifier|static
name|int
name|hOffset
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
specifier|static
name|bool
name|isThreeColumnEnumValueTable
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|)
block|;
ifdef|#
directive|ifdef
name|GENERATE_MAC_REFS
name|void
name|generateMacRef
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
endif|#
directive|endif
name|void
name|beginLink
argument_list|(
specifier|const
name|QString
operator|&
name|link
argument_list|)
block|;
name|void
name|endLink
argument_list|()
block|;
name|QString
name|writeGuidAttribute
argument_list|(
argument|QString text
argument_list|)
block|;
name|void
name|writeGuidAttribute
argument_list|(
name|Node
operator|*
name|node
argument_list|)
block|;
name|QString
name|lookupGuid
argument_list|(
argument|QString text
argument_list|)
block|;
name|QString
name|lookupGuid
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|GuidMap
operator|*
name|lookupGuidMap
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|virtual
name|void
name|beginSubPage
argument_list|(
argument|const InnerNode* node
argument_list|,
argument|const QString& fileName
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|endSubPage
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|generateInnerNode
argument_list|(
argument|InnerNode* node
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QXmlStreamWriter
operator|&
name|xmlWriter
argument_list|()
block|;
name|void
name|writeApiDesc
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|void
name|addLink
argument_list|(
argument|const QString& href
argument_list|,
argument|const QStringRef& text
argument_list|,
argument|DitaTag t = DT_xref
argument_list|)
block|;
name|void
name|writeDitaMap
argument_list|()
block|;
name|void
name|writeDitaMap
argument_list|(
specifier|const
name|DitaMapNode
operator|*
name|node
argument_list|)
block|;
name|void
name|writeStartTag
argument_list|(
argument|DitaTag t
argument_list|)
block|;
name|bool
name|writeEndTag
argument_list|(
argument|DitaTag t=DT_NONE
argument_list|)
block|;
name|DitaTag
name|currentTag
argument_list|()
block|;
name|void
name|clearSectionNesting
argument_list|()
block|{
name|sectionNestingLevel
operator|=
literal|0
block|; }
name|int
name|enterDesc
argument_list|(
argument|DitaTag tag
argument_list|,
argument|const QString& outputclass
argument_list|,
argument|const QString& title
argument_list|)
block|;
name|int
name|enterSection
argument_list|(
specifier|const
name|QString
operator|&
name|outputclass
argument_list|,
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|int
name|leaveSection
argument_list|()
block|;
name|bool
name|inSection
argument_list|()
specifier|const
block|{
return|return
operator|(
name|sectionNestingLevel
operator|>
literal|0
operator|)
return|;
block|}
name|int
name|currentSectionNestingLevel
argument_list|()
specifier|const
block|{
return|return
name|sectionNestingLevel
return|;
block|}
name|QStringList
name|metadataDefault
argument_list|(
argument|DitaTag t
argument_list|)
specifier|const
block|;
name|QString
name|stripMarkup
argument_list|(
argument|const QString& src
argument_list|)
specifier|const
block|;
name|Node
operator|*
name|collectNodesByTypeAndSubtype
argument_list|(
specifier|const
name|InnerNode
operator|*
name|parent
argument_list|)
block|;
name|void
name|writeDitaRefs
argument_list|(
specifier|const
name|DitaRefList
operator|&
name|ditarefs
argument_list|)
block|;
name|void
name|writeTopicrefs
argument_list|(
name|NodeMultiMap
operator|*
name|nmm
argument_list|,
specifier|const
name|QString
operator|&
name|navtitle
argument_list|,
name|Node
operator|*
name|headingnode
operator|=
literal|0
argument_list|)
block|;
name|bool
name|isDuplicate
argument_list|(
name|NodeMultiMap
operator|*
name|nmm
argument_list|,
specifier|const
name|QString
operator|&
name|key
argument_list|,
name|Node
operator|*
name|node
argument_list|)
block|;
name|void
name|debugPara
argument_list|(
specifier|const
name|QString
operator|&
name|t
argument_list|)
block|;
name|QString
name|ditaXmlHref
argument_list|(
name|Node
operator|*
name|n
argument_list|)
block|;
name|private
operator|:
comment|/*       These flags indicate which elements the generator       is currently outputting.      */
name|bool
name|inDetailedDescription
block|;
name|bool
name|inLegaleseText
block|;
name|bool
name|inObsoleteLink
block|;
name|bool
name|inTableBody
block|;
name|bool
name|noLinks
block|;
name|bool
name|obsoleteLinks
block|;
name|int
name|divNestingLevel
block|;
name|int
name|sectionNestingLevel
block|;
name|int
name|tableColumnCount
block|;
name|int
name|currentColumn
block|;
name|QRegExp
name|funcLeftParen
block|;
name|QString
name|style
block|;
name|QString
name|postHeader
block|;
name|QString
name|postPostHeader
block|;
name|QString
name|footer
block|;
name|QString
name|address
block|;
name|bool
name|pleaseGenerateMacRef
block|;
name|QString
name|project
block|;
name|QString
name|projectDescription
block|;
name|QString
name|projectUrl
block|;
name|QString
name|navigationLinks
block|;
name|QString
name|version
block|;
name|QStringList
name|vrm
block|;
name|QStringList
name|stylesheets
block|;
name|QStringList
name|customHeadElements
block|;
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|refMap
block|;
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|name2guidMap
block|;
name|GuidMaps
name|guidMaps
block|;
specifier|static
name|int
name|id
block|;
specifier|static
name|QString
name|ditaTags
index|[]
block|;
name|QStack
operator|<
name|QXmlStreamWriter
operator|*
operator|>
name|xmlWriterStack
block|;
name|QStack
operator|<
name|DitaTag
operator|>
name|tagStack
block|;
name|ConfigVarMultimap
name|metadataDefaults
block|;
name|QVector
operator|<
name|NodeMultiMap
operator|*
operator|>
name|nodeTypeMaps
block|;
name|QVector
operator|<
name|NodeMultiMap
operator|*
operator|>
name|nodeSubtypeMaps
block|;
name|QVector
operator|<
name|NodeMultiMap
operator|*
operator|>
name|pageTypeMaps
block|; }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|DITAXMLGENERATOR_ADDRESS
define|#
directive|define
name|DITAXMLGENERATOR_ADDRESS
value|"address"
end_define
begin_define
DECL|macro|DITAXMLGENERATOR_FOOTER
define|#
directive|define
name|DITAXMLGENERATOR_FOOTER
value|"footer"
end_define
begin_define
DECL|macro|DITAXMLGENERATOR_GENERATEMACREFS
define|#
directive|define
name|DITAXMLGENERATOR_GENERATEMACREFS
value|"generatemacrefs"
end_define
begin_define
DECL|macro|DITAXMLGENERATOR_POSTHEADER
define|#
directive|define
name|DITAXMLGENERATOR_POSTHEADER
value|"postheader"
end_define
begin_define
DECL|macro|DITAXMLGENERATOR_POSTPOSTHEADER
define|#
directive|define
name|DITAXMLGENERATOR_POSTPOSTHEADER
value|"postpostheader"
end_define
begin_define
DECL|macro|DITAXMLGENERATOR_STYLE
define|#
directive|define
name|DITAXMLGENERATOR_STYLE
value|"style"
end_define
begin_define
DECL|macro|DITAXMLGENERATOR_STYLESHEETS
define|#
directive|define
name|DITAXMLGENERATOR_STYLESHEETS
value|"stylesheets"
end_define
begin_define
DECL|macro|DITAXMLGENERATOR_CUSTOMHEADELEMENTS
define|#
directive|define
name|DITAXMLGENERATOR_CUSTOMHEADELEMENTS
value|"customheadelements"
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
