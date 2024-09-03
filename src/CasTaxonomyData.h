#pragma once

#include "CasTaxonomyData_export.h"

#include <RawData.h>
#include <Set.h>

const mv::DataType CasTaxonomyType = mv::DataType(QString("CasTaxonomy"));

// =============================================================================
// Raw Data
// =============================================================================
class CASTAXONOMYDATA_EXPORT CasTaxonomyData : public mv::plugin::RawData
{
    Q_OBJECT
public:
    CasTaxonomyData(const mv::plugin::PluginFactory* factory) :
        mv::plugin::RawData(factory, CasTaxonomyType)
    { }

    ~CasTaxonomyData(void) override;

    void init() override;

    /**
     * Create dataset for raw data
     * @param guid Globally unique dataset identifier (use only for deserialization)
     * @return Smart pointer to dataset
     */
    mv::Dataset<mv::DatasetImpl> createDataSet(const QString& guid = "") const override;

private:

};

// =============================================================================
// Data Set
// =============================================================================
class CASTAXONOMYDATA_EXPORT CasTaxonomy : public mv::DatasetImpl
{
public:
    CasTaxonomy(QString dataName, const QString& guid = "");
    ~CasTaxonomy() override;

    /**
     * Create subset and specify where the subset will be placed in the data hierarchy
     * @param guiName Name of the subset in the GUI
     * @param parentDataSet Smart pointer to parent dataset in the data hierarchy (default is below the set)
     * @param visible Whether the subset will be visible in the UI
     * @return Smart pointer to the created subset
     */
    mv::Dataset<mv::DatasetImpl> createSubsetFromSelection(const QString& guiName, const mv::Dataset<mv::DatasetImpl>& parentDataSet = mv::Dataset<mv::DatasetImpl>(), const bool& visible = true) const override;

    /** Mandatory override for copying of data sets */
    mv::Dataset<mv::DatasetImpl> copy() const override;

    //void setData(const std::vector<CellMorphology>& cellMorphologies);

    /**
     * Get set icon
     * @param color Icon color for flat (font) icons
     * @return Icon
     */
    QIcon getIcon(const QColor& color = Qt::black) const override;

public: // Selection

    /**
     * Get selection indices
     * @return Selection indices
     */
    std::vector<std::uint32_t>& getSelectionIndices() override;

    /**
     * Select by indices
     * @param indices Selection indices
     */
    void setSelectionIndices(const std::vector<std::uint32_t>& indices) override;

    /** Determines whether items can be selected */
    bool canSelect() const override;

    /** Determines whether all items can be selected */
    bool canSelectAll() const override;

    /** Determines whether there are any items which can be deselected */
    bool canSelectNone() const override;

    /** Determines whether the item selection can be inverted (more than one) */
    bool canSelectInvert() const override;

    /** Select all items */
    void selectAll() override;

    /** Deselect all items */
    void selectNone() override;

    /** Invert item selection */
    void selectInvert() override;

private:

};

// =============================================================================
// Factory
// =============================================================================

class CasTaxonomyDataFactory : public mv::plugin::RawDataFactory
{
    Q_INTERFACES(mv::plugin::RawDataFactory mv::plugin::PluginFactory)
    Q_OBJECT
    Q_PLUGIN_METADATA(IID   "studio.manivault.CasTaxonomyData"
                      FILE  "CasTaxonomyData.json")

public:
    CasTaxonomyDataFactory(void) {}
    ~CasTaxonomyDataFactory(void) override {}

    /**
     * Get plugin icon
     * @param color Icon color for flat (font) icons
     * @return Icon
     */
    QIcon getIcon(const QColor& color = Qt::black) const override;

    mv::plugin::RawData* produce() override;

    mv::DataTypes supportedDataTypes() const override;
};
