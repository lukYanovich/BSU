import { Injectable } from '@angular/core';
import {Http} from "@angular/http";


@Injectable()
export class ItemService {

    constructor(private _http: Http) {}

    getItems() {
        return this._http.get('app/resources/data-files/items.json');
    }

    getAbout(id: number) {
        switch (id) {
            case 1:
                return this._http.get('app/resources/data-files/one.json');
            case 2:
                return this._http.get('app/resources/data-files/two.json');
            case 3:
                return this._http.get('app/resources/data-files/three.json');
            default:
                return;
        }
    }
}