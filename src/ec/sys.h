#pragma once

// Generales
template <typename TComponent>
inline TComponent&       createComponentGeneral(TComponent* components, int& countComponents, int idEntity);

template <typename TComponent>
inline void              destroyComponentGeneral(TComponent* components, int& countComponents, int idEntity);

template <typename TComponent>
inline TComponent&       getComponentGeneral(TComponent* components, int countComponents, int idEntity);

// Sobre escritos
template <typename TComponent>
inline TComponent& createComponent(int idEntity) {}

template <typename TComponent>
inline void        destroyComponent(int idEntity) {}

template <typename TComponent>
inline TComponent&  getComponent(int idEntity) {}

template <typename TComponent>
inline void         update() {}

#include <ec/sys.tpp>