/* Copyright (c) 2014-2016 "Omnidome" by cr8tr
 * Dome Mapping Projection Software (http://omnido.me).
 * Omnidome was created by Michael Winkelmann aka Wilston Oreo (@WilstonOreo)
 *
 * This file is part of Omnidome.
 *
 * Omnidome is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <omni/AffineTransform.h>

namespace omni {
    AffineTransform::AffineTransform() :
        scale_(1.0,1.0,1.0),
        translation_(0.0,0.0,0.0) {
    }

    EulerAngles const& AffineTransform::rotation() const {
        return rotation_;
    }

    EulerAngles& AffineTransform::rotation() {
        return rotation_;
    }

    void AffineTransform::setRotation(EulerAngles const& _rotation) {
        rotation_ = _rotation;
    }

    QVector3D const& AffineTransform::scale() const {
        return scale_;
    }

    QVector3D& AffineTransform::scale() {
        return scale_;
    }

    void AffineTransform::setScale(QVector3D const& _scale) {
        scale_ = _scale;
    }

    QVector3D const& AffineTransform::translation() const {
        return translation_;
    }

    QVector3D& AffineTransform::translation() {
        return translation_;
    }

    void AffineTransform::setTranslation(QVector3D const& _translation) {
        translation_ = _translation;
    }

    QMatrix4x4 AffineTransform::matrix() const {
        return matrix(QVector3D(0.0,0.0,0.0));
    }

    QMatrix4x4 AffineTransform::matrix(QVector3D const& _center) const {
        QMatrix4x4 _m;
        _m.translate(_center);
        _m.translate(translation_);
        _m *= rotation_.matrix();
        _m.scale(scale_);
        _m.translate(-_center);
        return _m;
    }
}