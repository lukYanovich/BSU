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
var ItemService_1 = require("../add-class/ItemService");
var Three = /** @class */ (function () {
    function Three(_itemService) {
        this._itemService = _itemService;
    }
    Three.prototype.ngOnInit = function () {
        var _this = this;
        this._itemService.getAbout(3).subscribe(function (data) { return _this.item_about = data.json(); });
    };
    Three = __decorate([
        core_1.Component({
            selector: "my-three",
            styleUrls: ['./app/resources/style/style.css'],
            template: "\n        <div *ngIf=\"item_about\" class=\"right-menu\"> {{ item_about?.data }}</div>\n    "
        }),
        __metadata("design:paramtypes", [ItemService_1.ItemService])
    ], Three);
    return Three;
}());
exports.Three = Three;
//# sourceMappingURL=three.js.map