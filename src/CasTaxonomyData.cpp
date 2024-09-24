#include "CasTaxonomyData.h"

#include "Taxonomy.h"

Q_PLUGIN_METADATA(IID "studio.manivault.CasTaxonomyData")

using namespace mv;
using namespace mv::gui;

// =============================================================================
// View
// =============================================================================

CasTaxonomyData::~CasTaxonomyData(void)
{

}

void CasTaxonomyData::init()
{

}

/**
 * Create a new dataset linking back to the original raw data
 */
Dataset<DatasetImpl> CasTaxonomyData::createDataSet(const QString& guid /*= ""*/) const
{
    return new CasTaxonomy(getName(), guid);
}

CasTaxonomy::CasTaxonomy(QString dataName, const QString& guid /*= ""*/) :
    mv::DatasetImpl(dataName, true, guid)
{

}

CasTaxonomy::~CasTaxonomy()
{

}

Dataset<DatasetImpl> CasTaxonomy::createSubsetFromSelection(const QString& guiName, const Dataset<DatasetImpl>& parentDataSet /*= Dataset<DatasetImpl>()*/, const bool& visible /*= true*/) const
{
    return mv::data().createSubsetFromSelection(getSelection<CasTaxonomy>(), const_cast<CasTaxonomy*>(this), guiName, parentDataSet, visible);
}

Dataset<DatasetImpl> CasTaxonomy::copy() const
{
    auto copySet = new CasTaxonomy(getRawDataName());

    return copySet;
}

//void CasTaxonomy::setData(const std::vector<CellMorphology>& cellMorphologies)
//{
//    getRawData<CellMorphologyData>()->setData(cellMorphologies);
//}

QIcon CasTaxonomy::getIcon(const QColor& color /*= Qt::black*/) const
{
    return QIcon(":cas_taxonomy/Icon_64.png");
}

std::vector<std::uint32_t>& CasTaxonomy::getSelectionIndices()
{
    std::vector<std::uint32_t> temp;
    return temp;
}

void CasTaxonomy::setSelectionIndices(const std::vector<std::uint32_t>& indices)
{
    
}

bool CasTaxonomy::canSelect() const
{
    return false;
}

bool CasTaxonomy::canSelectAll() const
{
    return false;
}

bool CasTaxonomy::canSelectNone() const
{
    return canSelect() && (getSelectionSize() >= 1);
}

bool CasTaxonomy::canSelectInvert() const
{
    return canSelect();
}

void CasTaxonomy::selectAll()
{
    
}

void CasTaxonomy::selectNone()
{
    
}

void CasTaxonomy::selectInvert()
{
    
}

// =============================================================================
// Factory
// =============================================================================

mv::plugin::RawData* CasTaxonomyDataFactory::produce()
{
    return new CasTaxonomyData(this);
}

QIcon CasTaxonomyDataFactory::getIcon(const QColor& color /*= Qt::black*/) const
{
    return Application::getIconFont("FontAwesome").getIcon("database");
}

DataTypes CasTaxonomyDataFactory::supportedDataTypes() const
{
    DataTypes supportedTypes;
    return supportedTypes;
}
