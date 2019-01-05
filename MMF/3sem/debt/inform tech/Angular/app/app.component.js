"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
Object.defineProperty(exports, "__esModule", { value: true });
var core_1 = require("@angular/core");
var ItemService_1 = require("./resources/add-class/ItemService");
var AppComponent = /** @class */ (function () {
    function AppComponent(_itemService) {
        this._itemService = _itemService;
    }
    AppComponent.prototype.ngOnInit = function () {
        var _this = this;
        this._itemService.getItems().subscribe(function (data) { return _this.items = data.json(); });
    };
    AppComponent = __decorate([
        core_1.Component({
            selector: 'my-app',
            styleUrls: ['./app/resources/style/style.css'],
            template: "\n        <div class=\"content\"></div>\n\n        <ul>\n            <li *ngFor=\"let item of items\">\n                <!--<a [attr.href]=\"'#'+item.id\">-->\n                <a [routerLink]=\"[item.id]\">\n                    <div class=\"left-menu my-shadow\">\n                        <div class=\"innertext\">\n                            {{ item?.name }}\n                        </div>\n                    </div>\n                </a>\n            </li>\n        </ul>\n\n        <router-outlet></router-outlet>\n    "
        }),
        __metadata("design:paramtypes", [ItemService_1.ItemService])
    ], AppComponent);
    return AppComponent;
}());
exports.AppComponent = AppComponent;
//# sourceMappingURL=app.component.js.map