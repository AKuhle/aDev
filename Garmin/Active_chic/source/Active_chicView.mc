import Toybox.Application;
import Toybox.Graphics;
import Toybox.Lang;
import Toybox.System;
import Toybox.WatchUi;
import Toybox.Math;

import "Utils.mc" as MU;

class Active_chicView extends WatchUi.WatchFace {

    function initialize() {
        WatchFace.initialize();
    }

    // Load your resources here
    function onLayout(dc as Dc) as Void {
        setLayout(Rez.Layouts.WatchFace(dc));
    }

    // Called when this View is brought to the foreground. Restore
    // the state of this View and prepare it to be shown. This includes
    // loading resources into memory.
    function onShow() as Void {
    }

    // Update the view
    function onUpdate(dc as Dc) as Void {
        // Get the current time and format it correctly
        var timeFormat = "$1$:$2$";
        var clockTime = System.getClockTime();
        var hours = clockTime.hour;
        if (!System.getDeviceSettings().is24Hour) {
            if (hours > 12) {
                hours = hours - 12;
            }
        } else {
            if (Application.Properties.getValue("UseMilitaryFormat")) {
                timeFormat = "$1$$2$";
                hours = hours.format("%02d");
            }
        }
        var timeString = Lang.format(timeFormat, [hours, clockTime.min.format("%02d")]);

        // Update the view
        var view = View.findDrawableById("TimeLabel") as Text;
        view.setColor(Application.Properties.getValue("ForegroundColor") as Number);
        view.setText(timeString);

        // Call the parent onUpdate function to redraw the layout
        View.onUpdate(dc);

        // draw the steps
        drawSteps(dc);

        // draw the stairs
        drawStairs(dc);
    }

    // Called when this View is removed from the screen. Save the
    // state of this View here. This includes freeing resources from
    // memory.
    function onHide() as Void {
    }

    // The user has just looked at their watch. Timers and animations may be started here.
    function onExitSleep() as Void {
    }

    // Terminate any active timers and prepare for slow updates.
    function onEnterSleep() as Void {
    }

    // Terminate any active timers and prepare for slow updates.
    function drawSteps(dc as Dc) as Void {
        var screenWidth = dc.getWidth();
        var screenHeight = dc.getHeight();
        var centerX = screenWidth / 2;
        var centerY = screenHeight / 2;
        var radius = MU.min(screenWidth, screenHeight) / 2;

        dc.setColor(Graphics.COLOR_RED, Graphics.COLOR_TRANSPARENT);
        dc.setPenWidth(10);
        dc.drawCircle(centerX, centerY, radius);
    }

    // Terminate any active timers and prepare for slow updates.
    function drawStairs(dc as Dc) as Void {
        var values = [3, 7, 5, 8, 2, 9, 4, 6, 1, 10];
        drawLineChart(dc, 10, 10, 200, 100, values);
    }

    function drawLineChart(dc as Dc, x, y, w, h, values as Array<Number>) as Void {
        var n = values.size();
        if (n < 2) { return; }

        // Min/Max bestimmen
        var minVal = values[0];
        var maxVal = values[0];
        for (var i = 1; i < n; i += 1) {
            if (values[i] < minVal) minVal = values[i];
            if (values[i] > maxVal) maxVal = values[i];
        }
        if (maxVal == minVal) { maxVal += 1; minVal -= 1; } // Vermeide Division durch 0

        // Schriftgröße automatisch bestimmen
        var fontSize = h / 6;
        if (fontSize < 10) fontSize = 10;
        if (fontSize > 24) fontSize = 24;

        // Achsen zeichnen
        dc.setColor(Graphics.COLOR_WHITE, Graphics.COLOR_TRANSPARENT);
        dc.drawLine(x, y, x, y + h); // Y-Achse
        dc.drawLine(x, y + h, x + w, y + h); // X-Achse

        // Min/Max-Beschriftung
        dc.drawText(x + 2, y - fontSize/2, Graphics.FONT_SMALL, maxVal.format("%.1f"));
        dc.drawText(x + 2, y + h - fontSize/2, Graphics.FONT_SMALL, minVal.format("%.1f"));

        // Werte als Linie verbinden
        var step = w / (n - 1);
        var prevX = x;
        var prevY = y + h - ((values[0] - minVal) / (maxVal - minVal)) * h;

        dc.setColor(Graphics.COLOR_BLUE, Graphics.COLOR_TRANSPARENT);
        for (var i = 1; i < n; i += 1) {
            var currX = x + i * step;
            var currY = y + h - ((values[i] - minVal) / (maxVal - minVal)) * h;
            dc.drawLine(prevX, prevY, currX, currY);
            prevX = currX;
            prevY = currY;
        }
    } // drawLineChart

}


// permanente variablen:
// =====================
//Um permanente Variablen in Garmin Connect IQ zu speichern, die auch nach dem Beenden und Neustarten des Watchfaces erhalten bleiben, verwendest du das Modul Toybox.Application.Properties. Damit kannst du Werte dauerhaft speichern und später wieder auslesen.
//
//Beispiel: Permanente Variable speichern und laden
//Speichern:
//var arr = [1.1, 2.2, 3.3];
//Application.Properties.setValue("myArray", arr);
//Application.Properties.save();
//
//Laden:
//var arr = Application.Properties.getValue("myArray");
//if (arr == null) {
//    // Noch kein Wert gespeichert, Standardwerte setzen
//    arr = [0.0, 0.0, 0.0];
//}
//
//Hinweise:
//
//Die Daten bleiben auch nach einem Neustart oder Geräte-Neustart erhalten.
//Du kannst Zahlen, Strings, Arrays und Dictionaries speichern.
//Nach dem Setzen von Werten solltest du immer Application.Properties.save() aufrufen, damit die Daten wirklich geschrieben werden.
//Beispiel im Kontext:
//
//Fazit:
//Verwende Application.Properties für permanente Variablen in deinem Watchface.
//
//
//Du kannst ein Array mit drei Double-Werten in Garmin Connect IQ wie folgt permanent speichern und laden:
//
//Speichern:
//
//Laden:
//
//Hinweis:
//Arrays (und auch Dictionaries) können direkt mit Application.Properties gespeichert und geladen werden.


