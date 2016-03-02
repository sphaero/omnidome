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

#include <QWidget>
#include <QColor>
#include <QRect>
#include <QPoint>
#include <omni/ui/mixin/SessionWidget.h>
#include <omni/ui/mixin/TransformedRect.h>

namespace omni {
    namespace ui {
        class OutputPreview:
            public QWidget,
            public mixin::SessionWidget,
            public mixin::TransformedRect<OutputPreview>
        {
            Q_OBJECT
        public:
            OutputPreview(QWidget* = nullptr);
            ~OutputPreview();

            QRect desktopRect() const;

            RenderOptions const& renderOptions() const;
            void setRenderOptions(RenderOptions const&);

        public slots:
            void render();

        protected:
            void resizeEvent(QResizeEvent*);
            void paintEvent(QPaintEvent*);

        private:
            void drawBorder(QColor _color, QRect const& _rect, QPoint& _capPos, QString const& _caption);

            /// Return non transformed rectangle for tuning
            QRect getRectForTuning(proj::Tuning const*);

            void sessionParameters();

            RenderOptions renderOptions_;
            QImage image_;
        };
    }
}