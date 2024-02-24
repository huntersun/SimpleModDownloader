#pragma once

#include <borealis.hpp>

#include "api/mod.hpp"
#include "api/game.hpp"

class ModCell : public brls::RecyclerCell
{
  public:
    ModCell();

    BRLS_BIND(brls::Rectangle, accent, "brls/sidebar/item_accent");
    BRLS_BIND(brls::Label, label, "title");
    BRLS_BIND(brls::Label, subtitle, "subtitle");
    
    //TODO : Multithreaded image loading
    //BRLS_BIND(brls::Image, image, "image");

    static ModCell* create();
};

class ModData : public brls::RecyclerDataSource 
{
public:
    ModData(Game game);

    int numberOfSections(brls::RecyclerFrame* recycler) override;
    int numberOfRows(brls::RecyclerFrame* recycler, int section) override;
    brls::RecyclerCell* cellForRow(brls::RecyclerFrame* recycler, brls::IndexPath index) override;
    void didSelectRowAt(brls::RecyclerFrame* recycler, brls::IndexPath indexPath) override;
    std::string titleForHeader(brls::RecyclerFrame* recycler, int section) override;
private:
    Game& game;
    std::unique_ptr<ModList> modList;
    //ModList* modList;
};

class ModListTab : public brls::Box {
public:
    ModListTab();

    void setGame(const Game& game);

    static brls::View* create();

private:
    BRLS_BIND(brls::RecyclerFrame, recycler, "recycler");

    std::unique_ptr<ModData> modData;

};