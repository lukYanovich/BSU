"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
Object.defineProperty(exports, "__esModule", { value: true });
var core_1 = require("@angular/core");
var app_component_1 = require("./app.component");
var platform_browser_1 = require("@angular/platform-browser");
var http_1 = require("@angular/http");
var forms_1 = require("@angular/forms");
var router_1 = require("@angular/router");
var one_1 = require("./resources/add-components/one");
var ItemService_1 = require("./resources/add-class/ItemService");
var two_1 = require("./resources/add-components/two");
var three_1 = require("./resources/add-components/three");
var MyAppAppModule = /** @class */ (function () {
    function MyAppAppModule() {
    }
    MyAppAppModule = __decorate([
        core_1.NgModule({
            imports: [
                platform_browser_1.BrowserModule,
                http_1.HttpModule,
                forms_1.FormsModule,
                router_1.RouterModule.forRoot([
                    {
                        path: "1",
                        component: one_1.One
                    },
                    {
                        path: "2",
                        component: two_1.Two
                    },
                    {
                        path: "3",
                        component: three_1.Three
                    }
                ])
            ],
            declarations: [app_component_1.AppComponent, one_1.One, two_1.Two, three_1.Three],
            bootstrap: [app_component_1.AppComponent],
            providers: [ItemService_1.ItemService]
        })
    ], MyAppAppModule);
    return MyAppAppModule;
}());
exports.MyAppAppModule = MyAppAppModule;
//# sourceMappingURL=app.module.js.map