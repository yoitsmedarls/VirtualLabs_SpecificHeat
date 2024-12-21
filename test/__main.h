#pragma once
void updateWaterAndMetalInfoText(std::shared_ptr<Renderable> r_waterInfo,
                                 std::shared_ptr<vl::Laboratory> laboratory,
                                 std::shared_ptr<Renderable> r_metalInfo);

void placeBeakerOnHotPlate(std::shared_ptr<vl::HotPlate> hotplate,
                           std::shared_ptr<vl::Beaker> beaker,
                           std::shared_ptr<Renderable> r_waterInfo,
                           std::shared_ptr<Renderable> r_metalInfo,
                           std::shared_ptr<Renderable> r_waterAndMetalInfoPane,
                           std::shared_ptr<Renderable> r_beaker,
                           std::shared_ptr<Renderable> r_hotplate);

void removeBeakerOnHotPlate(std::shared_ptr<vl::HotPlate> hotplate,
                            std::shared_ptr<Renderable> r_waterInfo,
                            std::shared_ptr<Renderable> r_metalInfo,
                            std::shared_ptr<Renderable> r_waterAndMetalInfoPane,
                            std::shared_ptr<Renderable> r_beaker,
                            std::shared_ptr<Renderable> r_hotplate);
